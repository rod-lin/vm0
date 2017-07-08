#include "vm/type.h"

typedef struct vm0_value_t_tag {
	struct {
		vm0_byte_t type;
		vm0_byte_t pad[7];
	} h; // header: 64

	union vm0_value_t_union {
		vm0_int32_t i; // c0 int
		vm0_ptr_t p; // any pointer type
		struct vm0_array_t_tag *a; // array
	} v; // max: 64
} vm0_value_t;

#define vm0_value_buildInt(val) ((vm0_value_t) {	\
	{ VM0_TYPE_INT32 },								\
	(union vm0_value_t_union) { .i = (val) }		\
})

#define vm0_value_getInt(val) ((val).v.i)
#define vm0_value_getPtr(val) ((val).v.p)
#define vm0_value_getArray(val) ((val).v.a)

#define vm0_value_type(val) ((val).h.type)

typedef struct vm0_array_t_tag {
	vm0_size_t size;
	vm0_value_t lst[];
} vm0_array_t;
