#include "monty.h"

/**
 * swap - swaps top two elements of a stack_t stack
 * @stack: pointer to head
 * @line_number: line number
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp1, *temp2;

	temp1 = *stack;
	if (temp1->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		errno = 1;
		return;
	}
	temp2 = temp1->next;
	temp1->next = temp2->next;
	temp1->prev = temp2;
	temp2->prev = NULL;
	temp2->next = temp1;
	if (temp1->next)
	{
		temp2 = temp1->next;
		temp2->prev = temp1;
	}
	*stack = temp1->prev;
}
