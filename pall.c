#include "monty.h"

/**
 * pall - prints stack_t list
 * @stack: pointer to head node
 * @line_number: line number
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
