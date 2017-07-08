#include "vm/alloc.h"
#include "vm/stack.h"

vm0_stack_t
vm0_stack_init(vm0_size_t init)
{
	vm0_stack_t ret;

	ret.top = ret.bottom = vm0_ralloc(sizeof(*ret.bottom) * init);
	ret.edge = ret.bottom + init;

	return ret;
}
