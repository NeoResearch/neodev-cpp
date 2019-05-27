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

// bigger components
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

// smaller fields (attributes, parameters, ...)
class WasmField
{
public:
   string fieldName;
   vector<string> options;

   WasmField(string _fieldName, vector<string> _options)
     : fieldName(_fieldName)
     , options(_options)
   {
   }

   // convert to S-expression
   virtual string toSExpr()
   {
      stringstream ss;
      ss << fieldName;
      for (unsigned i = 0; i < options.size(); i++)
         ss << " " << options[i];
      ss << ")";
      return ss.str();
   }

   // only single line consumption
   static WasmField* parseField(Scanner& scanLine);
};

// complex fields and commands
class WasmCommand
{
public:
   string cmdName;
   vector<string> options;
   vector<WasmCommand*> commands;

   WasmCommand(string _cmdName, vector<string> _options, vector<WasmCommand*> _commands)
     : cmdName(_cmdName)
     , options(_options)
     , commands(_commands)
   {
   }

   // convert to S-expression
   virtual string toSExpr()
   {
      stringstream ss;
      ss << cmdName;
      for (unsigned i = 0; i < options.size(); i++)
         ss << " " << options[i];
      ss << ")";
      return ss.str();
   }

   static WasmCommand* parseCommand(Scanner& scanLine, Scanner& scanText);
};

// ===================================================================

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

class WasmData : public WasmComponent
{
public:
   WasmField* field;
   string value;

   WasmData()
     : WasmComponent("data")
   {
   }

   static WasmData* parseData(string line, Scanner& scanner)
   {
      Scanner scanLine(line);
      string type = scanLine.next();
      if (type != "(data") {
         cerr << "found '" << type << "'" << endl;
         error("expected '(data'");
      }

      WasmData* wdata = new WasmData();
      if (!wdata)
         error("wdata->field should not be null!");
      //cout << "WILL READ DATA!!" << endl;
      wdata->field = WasmField::parseField(scanLine);
      string value = Scanner::trim(scanLine.nextLine());
      //cout << "DATA='" << value << "'" << endl;
      wdata->value = value.substr(0, value.size() - 1);

      return wdata;
   }

   // convert to s-expression
   virtual string toSExpr()
   {
      stringstream ss;
      ss << "(data " << field->toSExpr() << " " << value << ")";
      return ss.str();
   }
};

class WasmExport : public WasmComponent
{
public:
   string sname; // string name
   string name;  // function name

   WasmExport()
     : WasmComponent("export")
   {
   }

   static WasmExport* parseExport(string line, Scanner& scanner)
   {
      Scanner scanLine(line);
      string type = scanLine.next();
      if (type != "(export") {
         cerr << "found '" << type << "'" << endl;
         error("expected '(export'");
      }

      WasmExport* wexport = new WasmExport();
      string sname = scanLine.next();
      string func = scanLine.next();
      string name = scanLine.next();
      wexport->sname = sname;
      wexport->name = name.substr(0, name.length() - 2);

      return wexport;
   }

   // convert to s-expression
   virtual string toSExpr()
   {
      stringstream ss;
      ss << "(export " << sname << " (func " << name << "))";
      return ss.str();
   }
};

// Function implementation
class WasmFunc : public WasmComponent
{
public:
   string name; // function name
   vector<WasmField*> parameters;
   vector<WasmField*> locals; // local fields
   vector<WasmCommand*> commands;

   WasmFunc()
     : WasmComponent("func")
   {
   }

   static WasmFunc* parseFunc(string line, Scanner& scanner)
   {
      Scanner scanLine(line);
      string type = scanLine.next();
      if (type != "(func") {
         cerr << "found '" << type << "'" << endl;
         error("expected '(func'");
      }

      WasmFunc* wfunc = new WasmFunc();
      string name = scanLine.next();
      wfunc->name = name;

      cout << "will read fields for function: " << name << endl;
      // consume parameters
      while (scanLine.hasNext()) {
         WasmField* param = WasmField::parseField(scanLine);
         if (!param)
            error("func PARAM IS NULL!!");
         wfunc->parameters.push_back(param);
      }

      cout << "FUNC consumed parameters!" << endl;

      string endline = Scanner::trim(scanner.nextLine());
      while (endline != ")") {
         cout << "-----> parseFunc: got line '" << endline << "'" << endl;
         Scanner scanLineTestLocal(endline);
         string testLocal = scanLineTestLocal.next();
         if (testLocal == "(local") {
            Scanner scanLocal(endline);
            WasmField* local = WasmField::parseField(scanLocal);
            if (!local)
               error("error reading local!");
            wfunc->locals.push_back(local);
         } else // command
         {
            Scanner scanLine2(endline);
            WasmCommand* cmd = WasmCommand::parseCommand(scanLine2, scanner);
            cout << "FUNC got command!" << endl;
            if (!cmd)
               error("COMMAND IS NULL ON FUNC!!");

            wfunc->commands.push_back(cmd);
         }

         endline = Scanner::trim(scanner.nextLine());
      }

      cout << "FOUND CLOSING FUNC" << endl;

      return wfunc;
   }

   // convert to s-expression
   virtual string toSExpr()
   {
      stringstream ss;
      ss << "(func " << name;
      for (unsigned i = 0; i < parameters.size(); i++)
         ss << " " << parameters[i]->toSExpr();
      ss << endl;
      for (unsigned i = 0; i < commands.size(); i++)
         ss << commands[i]->toSExpr() << endl;
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
   if (type == "(data")
      return WasmData::parseData(line, scanner);
   if (type == "(export")
      return WasmExport::parseExport(line, scanner);
   if (type == "(func")
      return WasmFunc::parseFunc(line, scanner);

   stringstream ss;
   ss << "unknown type: '" << type << "'";
   error(ss.str());
}

// Field may consume a single (current) line only
WasmField*
WasmField::parseField(Scanner& scanLine)
{
   string fieldName = scanLine.next();
   if (fieldName == "(i32.const") {
      string val = scanLine.next(); // e.g. (i32.const 40) -> on "(data"
      scanLine.nextLine();          // drop rest of line
      vector<string> options(1, val.substr(0, val.size() - 1));
      return new WasmField(fieldName, options);
   }

   if (fieldName == "(result") {
      string val = scanLine.next(); // e.g. (result i32) -> on "(func"
      scanLine.nextLine();          // drop rest of line
      vector<string> options(1, val.substr(0, val.size() - 1));
      return new WasmField(fieldName, options);
   }

   return nullptr;
}

// Command may consume a single (current) or multiple lines
WasmCommand*
WasmCommand::parseCommand(Scanner& scanLine, Scanner& scanText)
{
   string cmdName = scanLine.next();
   cout << "======> parseCommand: working with command: " << cmdName << endl;
   vector<string> options;
   vector<WasmCommand*> commands;

   // single line command
   if ((cmdName == "(i32.const") || (cmdName == "(call")) {
      cout << "GOT I32" << endl;
      string val = scanLine.next(); // e.g. (i32.const 40)
      scanLine.nextLine();          // drop rest of line
      vector<string> options(1, val.substr(0, val.size() - 1));
      cout << "creating new command!" << endl;
      return new WasmCommand(cmdName, options, commands);
   }

   // multi line command
   if ((cmdName == "(select") || (cmdName == "(i32.gt_s")) {
      scanLine.nextLine(); // drop rest of line
      string line2 = Scanner::trim(scanText.nextLine());
      while (line2 != ")") {
         Scanner scanLine2(line2);
         WasmCommand* cmd = WasmCommand::parseCommand(scanLine2, scanText);
         commands.push_back(cmd);
         line2 = Scanner::trim(scanText.nextLine());
      }
      return new WasmCommand(cmdName, options, commands);
   }

   cout << "RETURNING NULL COMMAND! READ '" << cmdName << "'" << endl;
   error("no command!");
   return nullptr;
}

// ===================================================================

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