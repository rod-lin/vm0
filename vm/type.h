#include <stdint.h>

typedef int8_t			vm0_int8_t;
typedef int16_t			vm0_int16_t;
typedef int32_t			vm0_int32_t;
typedef int64_t			vm0_int64_t;

typedef uint8_t			vm0_uint8_t;
typedef uint16_t		vm0_uint16_t;
typedef uint32_t		vm0_uint32_t;
typedef uint64_t		vm0_uint64_t;

typedef intptr_t		vm0_ptr_t;
typedef uintptr_t		vm0_uptr_t;

typedef vm0_uint8_t		vm0_byte_t;
typedef vm0_uint8_t		vm0_bool_t;
typedef vm0_uptr_t		vm0_size_t;

#define VM0_TYPE_INT32	0
#define VM0_TYPE_PTR	1
#define VM0_TYPE_ARRAY	2
