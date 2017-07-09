#ifndef VM0_VM_VALUE_H
#define VM0_VM_VALUE_H

#include "std/type.h"

typedef struct vm0_value_t_tag {
	struct {
		std_byte_t type;
		std_byte_t pad[7];
	} h; // header: 64

	union vm0_value_t_union {
		std_int32_t i; // c0 int
		std_ptr_t p; // any pointer type
		struct vm0_array_t_tag *a; // array
	} v; // max: 64
} vm0_value_t;

#define VM0_TYPE_INT32	0
#define VM0_TYPE_PTR	1
#define VM0_TYPE_ARRAY	2

#define vm0_value_buildInt(val) ((vm0_value_t) {	\
	{ VM0_TYPE_INT32 },								\
	(union vm0_value_t_union) { .i = (val) }		\
})

#define vm0_value_getInt(val) ((val).v.i)
#define vm0_value_getPtr(val) ((val).v.p)
#define vm0_value_getArray(val) ((val).v.a)

#define vm0_value_type(val) ((val).h.type)

typedef struct vm0_array_t_tag {
	std_size_t size;
	vm0_value_t lst[];
} vm0_array_t;

#endif
