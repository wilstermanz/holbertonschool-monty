#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = atoi(strtok(NULL, " \n"));
	return;
}
