#ifndef NEODEV_ABITYPE_UINT160_HPP
#define NEODEV_ABITYPE_UINT160_HPP

namespace neodev {

namespace abitype {

// On NeoVM level, UInt160 can be seen as a ByteArray (with 20 bytes)

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

struct UInt160
{
   //static int length();

   //static ByteArray concat(ByteArray ba);

   //failure: cannot be non-member
   //byte operator[](int index);
   //https://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B
};

} // namespace abitype

} // namespace devpack

#endif
