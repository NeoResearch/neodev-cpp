#include <iostream>
#include <sstream>
#include <vector>

#include "Scanner++/Scanner.h"

using namespace std;
using namespace scannerpp;

void
error(string msg)
{
   cerr << "error:" << msg << endl;
   exit(1);
}

class WasmComponent
{
public:
   string type;

   WasmComponent(string _type)
     : type(_type)
   {
   }

   // convert to S-expression
   virtual string toSExpr() = 0;

   static WasmComponent* parseComponent(string line, Scanner& scanner);
};

class WasmModule : public WasmComponent
{
public:
   vector<WasmComponent*> innerParts;

   WasmModule()
     : WasmComponent("module")
   {
   }

   static WasmModule* parseModule(string line, Scanner& scanner)
   {
      if (line != "(module")
         error("expected '(module'");

      WasmModule* module = new WasmModule();

      string line2 = scanner.nextLine();
      while (line2 != ")") {
         cout << "CURRENT MODULE:" << endl;
         cout << module->toSExpr() << endl;
         cout << endl;
         WasmComponent* component = WasmComponent::parseComponent(line2, scanner);
         module->innerParts.push_back(component);
         line2 = scanner.nextLine();
      }

      return module;
   }

   // convert to s-expression
   virtual string toSExpr()
   {
      stringstream ss;
      ss << "(module" << endl;
      for (unsigned i = 0; i < innerParts.size(); i++)
         ss << innerParts[i]->toSExpr() << endl;
      ss << ")";
      return ss.str();
   }
};

class WasmType : public WasmComponent
{
public:
   string name;

   WasmType()
     : WasmComponent("type")
   {
   }

   static WasmType* parseWType(string line, Scanner& scanner)
   {
      Scanner scanLine(line);
      string type = scanLine.next();
      if (type != "(type") {
         cerr << "found '" << type << "'" << endl;
         error("expected '(type'");
      }

      WasmType* wtype = new WasmType();
      string name = scanLine.next();
      wtype->name = name;

      return wtype;
   }

   // convert to s-expression
   virtual string toSExpr()
   {
      stringstream ss;
      ss << "(type"
         << " ";
      ss << name;
      //for (unsigned i = 0; i < innerParts.size(); i++)
      //   ss << innerParts[i]->toSExpr() << endl;
      ss << ")";
      return ss.str();
   }
};

class WasmImport : public WasmComponent
{
public:
   string name;

   WasmImport()
     : WasmComponent("import")
   {
   }

   static WasmImport* parseImport(string line, Scanner& scanner)
   {
      Scanner scanLine(line);
      string type = scanLine.next();
      if (type != "(import") {
         cerr << "found '" << type << "'" << endl;
         error("expected '(import'");
      }

      WasmImport* wimport = new WasmImport();
      string env = scanLine.next();
      string sname = scanLine.next();
      string func = scanLine.next();
      string name = scanLine.next();
      wimport->name = name;

      return wimport;
   }

   // convert to s-expression
   virtual string toSExpr()
   {
      stringstream ss;
      ss << "(import \"env\" ... " << name;
      //for (unsigned i = 0; i < innerParts.size(); i++)
      //   ss << innerParts[i]->toSExpr() << endl;
      ss << ")";
      return ss.str();
   }
};

class WasmTable : public WasmComponent
{
public:
   string name;

   WasmTable()
     : WasmComponent("table")
   {
   }

   static WasmTable* parseTable(string line, Scanner& scanner)
   {
      Scanner scanLine(line);
      string type = scanLine.next();
      if (type != "(table") {
         cerr << "found '" << type << "'" << endl;
         error("expected '(table'");
      }

      WasmTable* wtable = new WasmTable();

      return wtable;
   }

   // convert to s-expression
   virtual string toSExpr()
   {
      stringstream ss;
      ss << "(table ... ";
      //for (unsigned i = 0; i < innerParts.size(); i++)
      //   ss << innerParts[i]->toSExpr() << endl;
      ss << ")";
      return ss.str();
   }
};

class WasmMemory : public WasmComponent
{
public:
   string name;

   WasmMemory()
     : WasmComponent("memory")
   {
   }

   static WasmMemory* parseMemory(string line, Scanner& scanner)
   {
      Scanner scanLine(line);
      string type = scanLine.next();
      if (type != "(memory") {
         cerr << "found '" << type << "'" << endl;
         error("expected '(memory'");
      }

      WasmMemory* wmemory = new WasmMemory();

      return wmemory;
   }

   // convert to s-expression
   virtual string toSExpr()
   {
      stringstream ss;
      ss << "(memory ... ";
      //for (unsigned i = 0; i < innerParts.size(); i++)
      //   ss << innerParts[i]->toSExpr() << endl;
      ss << ")";
      return ss.str();
   }
};

// implementation of static method (general parser)
WasmComponent*
WasmComponent::parseComponent(string line, Scanner& scanner)
{
   Scanner scanLine(line);
   string type = scanLine.next();
   if (type == "(type")
      return WasmType::parseWType(line, scanner);
   if (type == "(import")
      return WasmImport::parseImport(line, scanner);
   if (type == "(table")
      return WasmTable::parseTable(line, scanner);
   if (type == "(memory")
      return WasmMemory::parseMemory(line, scanner);

   stringstream ss;
   ss << "unknown type: '" << type << "'";
   error(ss.str());
}

int
parseWat(string input, string output)
{
   Scanner scanner(new File(input));

   string line = scanner.nextLine();

   WasmModule* module = WasmModule::parseModule(line, scanner);

   cout << "parsed!" << endl;

   cout << endl;

   cout << "will print s-expression:" << endl;
   cout << module->toSExpr() << endl;

   cout << endl;

   cout << "will print json:" << endl;
   cout << module->toSExpr() << endl;

   cout << endl;

   cout << "finished successfully!" << endl;

   return 0;
}

int
usage()
{
   cout << "usage: wat2json input.wat -o output.json" << endl;
   return 1;
}

int
main(int argc, char* argv[])
{
   if (argc < 4)
      return usage();

   string input = argv[1];
   string o = argv[2];
   string output = argv[3];

   if (o != "-o")
      return usage();

   if ((input.length() <= 4) || (output.length() <= 5))
      return usage();

   string ext_input = input.substr(input.length() - 4, input.length());

   string ext_output = output.substr(output.length() - 5, output.length());

   if ((ext_input != ".wat") && (ext_input != "wast"))
      return usage();

   if (ext_output != ".json")
      return usage();

   return parseWat(input, output);
}