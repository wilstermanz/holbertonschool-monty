#include "monty.h"

/**
 * pint - prints int at top of stack
 * @stack: pointer to head of stack
 * @line_number: line number
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		errno = 1;
		return;
	}
	printf("%d\n", (*stack)->n);
}
