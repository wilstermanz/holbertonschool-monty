#include "monty.h"

/**
 * pop - removes top element of stack
 * @stack: points to head node
 * @line_number: line number
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		errno = 1;
		return;
	}

	*stack = temp->next;
	free(temp);
}
