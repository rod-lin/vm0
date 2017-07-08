#include <stdio.h>

#include "vm/stack.h"

int main()
{
	vm0_value_t val = vm0_value_buildInt(123);
	vm0_stack_t stack = vm0_stack_init(16);

	vm0_stack_push(stack, val);
	printf("%d\n", vm0_value_getInt(vm0_stack_pop(stack)));

	return 0;
}
