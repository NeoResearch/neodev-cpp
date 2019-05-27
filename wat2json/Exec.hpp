#ifndef CPP_EXEC_HPP
#define CPP_EXEC_HPP

#include <array>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>

#include "Scanner++/Scanner.h"

using namespace scannerpp;

namespace cppUtils {

struct CppFunction
{
   //std::string prefix;              // function namespace (not necessary to remove now...)
   std::string name;                // function name
   //std::string rtype;               // return type (not part of mangled name...)
   std::vector<std::string> params; // parameters
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
      if(mangled.length()==0)
      {
         cout << "empty function name to demangle!";
         exit(1);
      }
      if(mangled[0]=='$')
         mangled = mangled.substr(1, mangled.length()-1);
      cout << "DEMANGLING: " << mangled << endl;
      stringstream ss;
      ss << "c++filt " << mangled;
      //<< "_Z14GetArrayLengthN6neodev6vmtype9ByteArrayE";
      std::string ret = Scanner::trim(Exec::run(ss.str()));
      cout << "DEMANGLED: " << ret << endl;

      CppFunction cppf;      
      Scanner scanner(ret);
      scanner.useSeparators("(), ");
      cppf.name = scanner.next();
      while(scanner.hasNext())
         cppf.params.push_back(scanner.next());

      return cppf;
   }
};

} // cppUtils

#endif // CPP_EXEC_HPP