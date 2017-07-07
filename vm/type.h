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
typedef vm0_uptr_t		vm0_size_t;

typedef union vm0_value_t_tag {
	vm0_int32_t i; // c0 int
	vm0_ptr_t p; // any pointer type
	struct vm0_array_t_tag *a; // array
} vm0_value_t;

typedef struct vm0_array_t_tag {
	vm0_size_t size;
	vm0_value_t lst[];
} vm0_array_t;

typedef struct {
	vm0_value_t *bottom;
	vm0_value_t *top;
} vm0_stack_t;
