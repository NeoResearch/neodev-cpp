#ifndef NEODEV_SYSCALLS_HPP
#define NEODEV_SYSCALLS_HPP

namespace neodev {


// convert data types
// example: _convert_String should convert first parameter to String stackitem (this should be done on compile time)
#define CONVERT(x) template<typename _1 = _convert_##x>
struct _convert_String
{};


// just ignore function
#define NOEMIT() template<typename _1 = _noemit>
struct _noemit
{};


// emit a syscall named 'x'
// example: EMIT_SYSCALL(Neo_Storage_GetContext)
//  =>  _emit_syscall_Neo_Storage_GetContext
#define EMIT_SYSCALL(x) template<typename _ = _emit_syscall_##x>


// declare a syscall named 'x' (must be done once)
// example: DECLARE_SYSCALL(Neo_Storage_GetContext)
// => //struct _emit_syscall_Neo_Storage_GetContext { };
#define DECLARE_SYSCALL(x)  \
   struct _emit_syscall_##x \
   {};



// emit two syscalls named 'x1' and 'x2' (in this order)
#define EMIT_SYSCALL2(x1, x2) template<typename _1 = _emit_syscall_##x1, typename _2 = _emit_syscall_##x2>



DECLARE_SYSCALL(Neo_Storage_GetContext)
DECLARE_SYSCALL(Neo_Storage_Get)
DECLARE_SYSCALL(Neo_Storage_Put)
DECLARE_SYSCALL(Neo_Storage_Delete)
DECLARE_SYSCALL(Neo_Storage_Find)

DECLARE_SYSCALL(Neo_Iterator_Next)
DECLARE_SYSCALL(Neo_Iterator_Key)
DECLARE_SYSCALL(Neo_Iterator_Value)

} // namespace neodev

#endif // NEODEV_SYSCALLS_HPP
