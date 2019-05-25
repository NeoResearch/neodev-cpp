#include <iostream>

#include "Scanner++/Scanner.h"

using namespace std;
using namespace scannerpp;

int
parseWat(string input, string output)
{
 
   Scanner scanner(new File(input));
 
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