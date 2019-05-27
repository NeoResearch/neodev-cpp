#include <iomanip> // hex format
#include <iostream>
#include <sstream>
#include <vector>

#include "Scanner++/Scanner.h"

// execute external command
#include "Exec.hpp"

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

   // convert to JSON
   virtual string toJSON() = 0;

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

   // convert to JSON
   virtual string toJSON()
   {
      stringstream ss;
      ss << "{\"name\":\"" << fieldName << "\", \"params\":[";
      for (unsigned i = 0; i < options.size(); i++)
         ss << (i == 0 ? "" : ",") << "\"" << options[i] << "\"";
      ss << "]}";
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
      if (commands.size() == 0)
         ss << ")";
      else {
         ss << endl;
         for (unsigned i = 0; i < commands.size(); i++)
            ss << commands[i]->toSExpr() << endl;
         ss << ")";
      }
      return ss.str();
   }

   // convert to JSON
   virtual string toJSON()
   {
      stringstream ss;
      ss << "{\"cmd\":\"" << cmdName << "\"";
      if (options.size() > 0) {
         ss << ",\"params\":[";
         for (unsigned i = 0; i < options.size(); i++)
            ss << (i == 0 ? "" : ",") << "\"" << options[i] << "\"";
         ss << "]";
      }
      if (commands.size() > 0) {
         ss << ",\"deps\":[";
         for (unsigned i = 0; i < commands.size(); i++)
            ss << (i == 0 ? "" : ",") << commands[i]->toJSON() << endl;
         ss << "]";
      }
      ss << "}";

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
   virtual string toSExpr() override
   {
      stringstream ss;
      ss << "(module" << endl;
      for (unsigned i = 0; i < innerParts.size(); i++)
         ss << innerParts[i]->toSExpr() << endl;
      ss << ")";
      return ss.str();
   }

   // convert to JSON
   virtual string toJSON() override
   {
      stringstream ss;
      ss << "{\"declare\": \"module\", \"contents\":[" << endl;
      for (unsigned i = 0; i < innerParts.size(); i++)
         ss << (i == 0 ? "" : ",") << innerParts[i]->toJSON() << endl;
      ss << "]}";
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
   virtual string toSExpr() override
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

   // convert to JSON
   virtual string toJSON() override
   {
      stringstream ss;
      ss << "{\"declare\": \"type\",";
      ss << "\"name\":\"" << name << "\"";
      ss << "}";
      return ss.str();
   }
};

class WasmImport : public WasmComponent
{
public:
   string name;
   cppUtils::CppFunction cppf;

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
      Scanner cleanName(name);
      cleanName.useSeparators(")");
      wimport->name = cleanName.next(); // removing ')' from name
      wimport->cppf = cppUtils::Exec::demangle(wimport->name);

      return wimport;
   }

   // convert to s-expression
   virtual string toSExpr() override
   {
      stringstream ss;
      ss << "(import \"env\" ... " << name;
      //for (unsigned i = 0; i < innerParts.size(); i++)
      //   ss << innerParts[i]->toSExpr() << endl;
      ss << ")";
      return ss.str();
   }

   // convert to JSON
   virtual string toJSON() override
   {
      stringstream ss;
      ss << "{\"declare\":\"import\", \"type\": \"env\" , \"notimplemented\": true, \"name\":\"" << name << "\"";
      bool cppdemangle = true;
      if (cppdemangle) {
         ss << "," << cppUtils::CppFunction::toJSONField(cppf);
      }
      ss << "}";
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
   virtual string toSExpr() override
   {
      stringstream ss;
      ss << "(table ... ";
      //for (unsigned i = 0; i < innerParts.size(); i++)
      //   ss << innerParts[i]->toSExpr() << endl;
      ss << ")";
      return ss.str();
   }

   // convert to JSON
   virtual string toJSON() override
   {
      stringstream ss;
      ss << "{\"declare\": \"table\", \"notimplemented\": true ";
      ss << "}";
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
   virtual string toSExpr() override
   {
      stringstream ss;
      ss << "(memory ... ";
      //for (unsigned i = 0; i < innerParts.size(); i++)
      //   ss << innerParts[i]->toSExpr() << endl;
      ss << ")";
      return ss.str();
   }

   // convert to JSON
   virtual string toJSON() override
   {
      stringstream ss;
      ss << "{\"declare\": \"memory\", \"notimplemented\": true";
      ss << "}";
      return ss.str();
   }
};

class WasmData : public WasmComponent
{
public:
   WasmField* field;
   string value;

   string valToHexString(string val) const
   {
      if (val.length() == 0)
         return "";
      stringstream ss;
      int i = 0;
      if (val[0] == '"')
         i++; // skip first
      int n = val.length() - 1;
      if (val[n] == '"')
         n--; // skip last
      ss << "0x";
      while (i <= n) {
         if (val[i] == '\\') // hex digit
         {
            ss << val[i + 1] << val[i + 2];
            i += 3;
         } else // regular digit
         {
            stringstream s2;
            s2 << setfill('0') << setw(2) << std::hex << (int)((unsigned char)val[i]);
            ss << s2.str();
            //cout << " xxxxxxxxxxxxxxx converting char '" << val[i] << "' to " << s2.str() << endl;
            i++;
         }
      }
      return ss.str();
   }

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
   virtual string toSExpr() override
   {
      stringstream ss;
      ss << "(data " << field->toSExpr() << " " << value << ")";
      return ss.str();
   }

   // convert to JSON
   virtual string toJSON() override
   {
      stringstream ss;
      ss << "{\"declare\": \"data\", \"field\":" << field->toJSON() << ",\"value\":\"" << valToHexString(value) << "\"}";
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
   virtual string toSExpr() override
   {
      stringstream ss;
      ss << "(export " << sname << " (func " << name << "))";
      return ss.str();
   }

   // convert to JSON
   virtual string toJSON() override
   {
      stringstream ss;
      ss << "{\"declare\":\"export\", \"sname\": " << sname << ", \"func\": \"" << name << "\"}";
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

   cppUtils::CppFunction cppf; // beautiful demangled items

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
      wfunc->cppf = cppUtils::Exec::demangle(name);

      cout << "will read fields for function: " << name << endl;
      cout << "demangled name: " << wfunc->cppf.name << endl;
      cout << "parameter count: " << wfunc->cppf.params.size() << endl;
      for (unsigned i = 0; i < wfunc->cppf.params.size(); i++)
         cout << wfunc->cppf.params[i] << endl;
      cout << "template count: " << wfunc->cppf.templates.size() << endl;
      for (unsigned i = 0; i < wfunc->cppf.templates.size(); i++)
         cout << wfunc->cppf.templates[i] << endl;

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
   virtual string toSExpr() override
   {
      stringstream ss;
      ss << "(func " << name;
      for (unsigned i = 0; i < parameters.size(); i++)
         ss << " " << parameters[i]->toSExpr();
      ss << endl;
      for (unsigned i = 0; i < locals.size(); i++)
         ss << locals[i]->toSExpr() << endl;
      for (unsigned i = 0; i < commands.size(); i++)
         ss << commands[i]->toSExpr() << endl;
      ss << ")";
      return ss.str();
   }

   // convert to JSON
   virtual string toJSON() override
   {
      stringstream ss;
      ss << "{\"declare\":\"func\", \"name\":\"" << name << "\"";
      bool cppdemangle = true;
      if (cppdemangle) {
         ss << "," << cppUtils::CppFunction::toJSONField(cppf);
      }
      ss << ",\"params\":[";
      for (unsigned i = 0; i < parameters.size(); i++)
         ss << (i == 0 ? "" : ",") << parameters[i]->toJSON();
      ss << "]," << endl;
      if (locals.size() > 0) {
         ss << "\"locals\":[";
         for (unsigned i = 0; i < locals.size(); i++)
            ss << (i == 0 ? "" : ",") << locals[i]->toJSON();
         ss << "]," << endl;
      }
      ss << "\"commands\":[";
      for (unsigned i = 0; i < commands.size(); i++)
         ss << (i == 0 ? "" : ",") << commands[i]->toJSON() << endl;
      ss << "]}";
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
      //scanLine.nextLine();          // drop rest of line
      vector<string> options(1, val.substr(0, val.size() - 1));
      return new WasmField(fieldName, options);
   }

   if (fieldName == "(param") {
      string val1 = scanLine.next(); // e.g. (param $0 i32) -> on "(func"
      string val2 = scanLine.next(); // e.g. (param $0 i32) -> on "(func"
      //scanLine.nextLine();          // drop rest of line
      vector<string> options;
      options.push_back(val1);
      options.push_back(val2.substr(0, val2.size() - 1));
      return new WasmField(fieldName, options);
   }

   if (fieldName == "(result") {
      string val = scanLine.next(); // e.g. (result i32) -> on "(func"
      //scanLine.nextLine();          // drop rest of line
      vector<string> options(1, val.substr(0, val.size() - 1));
      return new WasmField(fieldName, options);
   }

   if (fieldName == "(local") {
      // e.g. (local $0 i32)
      string val1 = scanLine.next(); // e.g. $0
      string val2 = scanLine.next(); // e.g. i32)
      //scanLine.nextLine();           // drop rest of line
      vector<string> options;
      options.push_back(val1);
      options.push_back(val2.substr(0, val2.size() - 1));
      return new WasmField(fieldName, options);
   }

   cout << "PARSING FIELD '" << fieldName << "'" << endl;
   error("field cannot be null!");

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
   if ((cmdName == "(i32.const") || (cmdName == "(get_local")) {
      string val = scanLine.next(); // e.g. (i32.const 40)
      scanLine.nextLine();          // drop rest of line
      vector<string> options(1, val.substr(0, val.size() - 1));
      cout << "creating new command!" << endl;
      return new WasmCommand(cmdName, options, commands);
   }

   // disabled single line commands
   if ((cmdName == "(f32.const")) {
      error("FLOAT POINT OPERATIONS IS NOT SUPPORTED INSIDE NeoVM! USE (BIG)INTEGER");
      return nullptr;
   }

   // multi line command
   if ((cmdName == "(select") || (cmdName == "(i32.gt_s") || (cmdName == "(i32.sub") ||
       (cmdName == "(i32.add") || (cmdName == "(drop")) {
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

   // hybrid single and multiline
   if ((cmdName == "(i32.store") || (cmdName == "(i32.load") || (cmdName == "(tee_local") || (cmdName == "(set_local")) {
      string val = scanLine.next(); // e.g. offset=4 (on i32.store) or $0 (on tee_local)
      options.push_back(val);
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

   // hybrid single and multiline (special for call)
   if ((cmdName == "(call")) {
      // call may be single line: (call $function)
      // or it may be multiline: (call $function
      //                             more commands
      //                         )
      string val = scanLine.next();
      scanLine.nextLine();               // drop rest of line
      if (val.at(val.size() - 1) == ')') // single line
         options.push_back(val.substr(0, val.size() - 1));
      else {
         options.push_back(val);
         string line2 = Scanner::trim(scanText.nextLine());
         while (line2 != ")") {
            Scanner scanLine2(line2);
            WasmCommand* cmd = WasmCommand::parseCommand(scanLine2, scanText);
            commands.push_back(cmd);
            line2 = Scanner::trim(scanText.nextLine());
         }
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
   cout << module->toJSON() << endl;

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

   /*
   //cppUtils::CppFunction f = cppUtils::Exec::demangle("_Z14GetArrayLengthN6neodev6vmtype9ByteArrayE");
   cppUtils::CppFunction f = cppUtils::Exec::demangle("_ZN11NeoContract4mainEN6neodev7abitype6StringENS0_6vmtype5ArrayE");

   cout << f.name << endl;
   for (unsigned i = 0; i < f.params.size(); i++)
      cout << f.params[i] << endl;

   int x;
   cin >> x;
*/
   return parseWat(input, output);
}
