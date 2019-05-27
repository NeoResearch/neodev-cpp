#ifndef NEODEV_SYSCALLS_HPP
#define NEODEV_SYSCALLS_HPP

namespace neodev {

#define NOEMIT() template<typename _1 = _noemit>
struct _noemit
{};

#define EMIT_SYSCALL(x) template<typename _ = _emit_syscall_##x>

// example: EMIT_SYSCALL(Neo_Storage_GetContext) expands to _emit_syscall_Neo_Storage_GetContext

#define DECLARE_SYSCALL(x)  \
   struct _emit_syscall_##x \
   {};

// composite syscalls (manually for now)
#define EMIT_SYSCALL2(x1, x2) template<typename _1 = _emit_syscall_##x1, typename _2 = _emit_syscall_##x2>

// example: DECLARE_SYSCALL(Neo_Storage_GetContext)
// =>
//struct _emit_syscall_Neo_Storage_GetContext
//{
//};

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
