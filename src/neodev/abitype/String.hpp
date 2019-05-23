#ifndef NEODEV_ABITYPE_STRUCT_HPP
#define NEODEV_ABITYPE_STRUCT_HPP

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

struct String
{
   [[nodiscard]]
   static int length(); //__attribute__((nodiscard));

   // todo: operator[] ref
   [[nodiscard]]
   static char at(int index);

   // todo: operator[] ref
   static void set(int index, char value);

   //static ByteArray concat(ByteArray ba);

   //failure: cannot be non-member
   //byte operator[](int index);
   //https://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B
};

} // namespace abitype

} // namespace devpack

#endif
