#ifndef NEODEV_ABITYPE_STRUCT_HPP
#define NEODEV_ABITYPE_STRUCT_HPP

#include "../syscalls.hpp"
#include "../vmtype/StackItem.hpp"

#ifdef NEODEV_CPP_TEST
#include<string>
#endif 

namespace neodev {

namespace abitype {

// On NeoVM level, String can be seen as a ByteArray
// Anyway, useful programming functions String-related are provided here for developers

/**
 * @api {get} /user/:id Test Request User information
 * @apiName GetUser
 * @apiGroup User
 *
 * @apiParam {Number} id Users unique ID.
 *
 * @apiSuccess {String} firstname Firstname of the User.
 * @apiSuccess {String} lastname  Lastname of the User.
 */

struct String : vmtype::Object
{
   const int type = 0x07;

#ifdef NEODEV_CPP_TEST
   std::string str_base; // immutable class
   String(const char op[])
     : str_base(op)
   {
   }

   String() // why use this?
     : str_base("")
   {
   }

#endif

   // initializes an empty String (should not do anything, just a stub)
   static String init();

   [[nodiscard]] int length(); //__attribute__((nodiscard));

   // todo: operator[] ref
   [[nodiscard]] char at(int index);

   // todo: operator[] ref
   void set(int index, char value);

   //static ByteArray concat(ByteArray ba);

   //failure: cannot be non-member
   //byte operator[](int index);
   //https://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B
};

// convert const char (string) on neo abi String (or ByteArray)
// will probably read it from a "(data" field starting at a given position (i32.const value)
CONVERT(String)
String
str(const char op[]);

//String operator"" _S(const char op[], unsigned int size);
// TODO: think about operator"" ... working already for some compilers.

#ifdef NEODEV_CPP_TEST
CONVERT(String)
String
str(const char op[])
{
   return String(op);
}
#endif

} // namespace abitype

} // namespace devpack

#endif
