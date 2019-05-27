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
   void set(int index, byte value);

   // member operator
   //byte& operator[](int index); // generates i32.store 8... not good now.
};

} // namespace vmtype

} // namespace devpack

#endif
