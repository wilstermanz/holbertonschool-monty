#include "monty.h"

/**
 * add - Adds the top two elements of a stack_t list,
 * and removes extra node.
 * @stack: pointer to head node
 * @line_number: line number
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int n;

	n = temp->n;
	temp = temp->next;
	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		errno = 1;
		return;
	}
	free(temp->prev);
	temp->n += n;
	*stack = temp;
}
