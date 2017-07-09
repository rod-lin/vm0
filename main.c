#include <stdio.h>

#include "vm/stack.h"

int main()
{
	vm0_stack_t stack;

	vm0_stack_init(&stack, 16);

	for (int i = 0; i < 1024; i++) {
		vm0_stack_push(&stack, vm0_value_buildInt(i));
	}

	for (int i = 0; i < 10; i++) {
		printf("%d\n", vm0_value_getInt(vm0_stack_pop(&stack)));
	}

	vm0_stack_clean(&stack);

	return 0;
}
