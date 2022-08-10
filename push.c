#include "monty.h"

/**
 * push - Adds new node to stack_t list
 * stack: pointer to head node 
 * line_number: line number 
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *newNode;
	stack_t *temp = *stack;
	char *n;
	int i;
	
	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack_t(*stack);
		errno = 12;
		return;
	}
	newNode->prev = NULL;
	n = strtok(NULL, " \n");
	for (i = 0; n[i]; i++)
	{
		if ((n == NULL) || (isdigit(n[i]) != 0))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free(newNode);
			errno = 1;
			return;
		}
	}
	newNode->n = atoi(n);
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
