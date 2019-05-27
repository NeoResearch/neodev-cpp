#ifndef NEODEV_VMTYPE_BYTEARRAY_HPP
#define NEODEV_VMTYPE_BYTEARRAY_HPP

namespace neodev {

// helper type: byte
typedef unsigned char byte;
//struct byte {};

namespace vmtype {

/*
extern "C" int __op(int x)
{
  return 1;
}
*/

//int Size2(bytearray a);

//[[gnu::always_inline]]
//[[deprecated("because Bla")]]
//extern "C" int Size4() __attribute__((deprecated("tst"),alias("__op")));

struct ByteArray
{
   [[nodiscard]] static int length();

   [[nodiscard]] static ByteArray concat(ByteArray ba);

   // todo: operator[] ref
   [[nodiscard]] static byte at(int index);

   // todo: operator[] ref
   static void set(int index, byte value);

   //friend byte operator[](ByteArray b, int index)  __attribute__((deprecated("tst"),alias("__op")));

   //failure: cannot be non-member
   //byte operator[](int index);
   //https://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B
};

} // namespace vmtype

} // namespace devpack

#endif
