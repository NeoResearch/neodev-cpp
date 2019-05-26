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