#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *newNode;
	stack_t *temp = *stack;
	
	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack_t(*stack);
		errno = 12;
		return;
	}
	
	newNode->prev = NULL;
	newNode->n = atoi(strtok(NULL, " \n"));

	if (temp == NULL)
	{
		newNode->next = NULL;
		*stack = newNode;
		return;
	}

	newNode->next = temp;
	temp->prev = newNode;
	*stack = newNode;
}
