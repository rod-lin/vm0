#include "vm/value.h"

typedef struct {
	vm0_value_t *bottom;
	vm0_value_t *top;
	vm0_value_t *edge;
} vm0_stack_t;

vm0_stack_t
vm0_stack_init(vm0_size_t init);

#define vm0_stack_push(stack, val) (*((stack).top++) = (val))
#define vm0_stack_pop(stack) (*(--(stack).top))
