#ifndef CPP_EXEC_HPP
#define CPP_EXEC_HPP

#include <array>
#include <iostream>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>

#include "Scanner++/Scanner.h"

using namespace scannerpp;

namespace cppUtils {

struct CppFunction
{
   //std::string prefix;              // function namespace (not necessary to remove now...)
   std::string name;                   // function name
   std::string rtype;                  // return type (if part of mangled name). Templates have this, empty string otherwise.
   std::vector<std::string> params;    // parameters
   std::vector<std::string> templates; // parameters

   static string toJSONField(CppFunction cppf)
   {
      std::stringstream ss;
      ss << "\"cppdemangle\":{\"name\":\"" << cppf.name << "\"";
      //if(cppf.rtype!="") // if return type is known
      ss << ",\"rtype\":\"" << cppf.rtype << "\"";
      if (cppf.templates.size() > 0) // if has templates
      {
         ss << ",\"templates\":[";
         for (unsigned i = 0; i < cppf.templates.size(); i++)
            ss << (i == 0 ? "" : ",") << "\"" << cppf.templates[i] << "\"";
         ss << "]";
      }
      ss << ",\"params\":[";
      for (unsigned i = 0; i < cppf.params.size(); i++)
         ss << (i == 0 ? "" : ",") << "\"" << cppf.params[i] << "\"";
      ss << "]";
      ss << "}";
      return ss.str();
   }
};

// thanks to: https://stackoverflow.com/questions/478898/how-do-i-execute-a-command-and-get-output-of-command-within-c-using-posix#478960
class Exec
{
public:
   static std::string run(string command)
   {
      cout << "RUNNING COMMAND: '" << command << "'" << endl;
      const char* cmd = command.c_str();
      std::array<char, 128> buffer;
      std::string result;
      std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
      if (!pipe)
         throw std::runtime_error("popen() failed!");

      while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr)
         result += buffer.data();

      return result;
   }

   static CppFunction demangle(string mangled)
   {
      if (mangled.length() == 0) {
         cout << "empty function name to demangle!";
         exit(1);
      }
      if (mangled[0] == '$')
         mangled = mangled.substr(1, mangled.length() - 1);
      cout << "DEMANGLING: " << mangled << endl;
      stringstream ss;
      ss << "c++filt " << mangled;
      //<< "_Z14GetArrayLengthN6neodev6vmtype9ByteArrayE";
      // _ZN6neodev6vmtype5Array2atEi
      // _ZN11NeoContract7neomainIN6neodev15emit_entrypointEEEiNS1_7abitype6StringENS1_6vmtype5ArrayE
      std::string ret = Scanner::trim(Exec::run(ss.str()));
      cout << "DEMANGLED: " << ret << endl;

      CppFunction cppf;
      // step 1: look for templates and return value
      bool hasReturn = false;
      string returnValue = ""; // default empty string (unknown return value)
      if (ret.find("<") != -1)
      {
         hasReturn = true; // name mangling for templates include return value
         cout << "FOUND RETURN FOR: " << ret << endl;
      }
      Scanner scanner(ret);
      scanner.useSeparators("(), ");
      if (hasReturn)
         returnValue = scanner.next();
      cppf.rtype = returnValue;
      cppf.name = scanner.next();
      while (scanner.hasNext())
         cppf.params.push_back(scanner.next());

      // step 2: update template parameters
      Scanner scanName(cppf.name);
      scanName.useSeparators("<>,");
      cppf.name = scanName.next(); // real name (without templates)
      while (scanName.hasNext())
         cppf.templates.push_back(scanName.next());

      return cppf;
   }
};

} // cppUtils

#endif // CPP_EXEC_HPP