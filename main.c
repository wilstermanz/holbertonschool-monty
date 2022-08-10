#include "monty.h"

/**
 * main - Monty bitcode interpreter
 *
 * @argc: number of args passed
 * @argv: Array of args passed
 * Return: EXIT_SUCCESS, or EXIT_FAILURE
 */

int main(int argc, char *argv[])
{
	char *buffer = NULL;
	size_t buffsize = 0;
	FILE *fp;
	stack_t *stack = NULL;

	if (argc != 2)
		print_error(1, argv[1], 0, NULL);

	fp = fopen(argv[1], "r");
	if (fp == NULL)
		print_error(2, argv[1], 0, NULL);

	while ((getline(&buffer, &buffsize, fp) != EOF) && (errno == 0))
	{
		if (buffer == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			errno = 12;
		}
		instruction_checker(&buffer, &stack, argv[1]);
	}

	free_stack_t(stack);
	free(buffer);
	fclose(fp);

	if (errno != 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/**
 * instruction_checker - parses lines in file,
 * and compares to instruction_t array to find function pointer.
 * @buffer: pointer to buffer storing line from .m file
 * @stack: pointer to head of stack_t list
 * @file: name of file being read
 */

void instruction_checker(char **buffer, stack_t **stack, char *file)
{
	char *opcode = NULL;
	unsigned int  line_number = 0, i;
	instruction_t commands[] = {
	{"push", push},		{"pall", pall},
	{"pint", pint},		{"pop", pop},
	{"add", add},		{"nop", nop},
	{"swap", swap},		{NULL, NULL}
};

	line_number++;
		opcode = strtok(*buffer, " \n");
		for (i = 0; commands[i].opcode; i++)
		{
			if (strcmp(opcode, commands[i].opcode) == 0)
			{
				commands[i].f(&(*stack), line_number);
				break;
			}
		}
		if (commands[i].opcode == NULL)
		{
			print_error(3, file, line_number, opcode);
		}

		free(*buffer);
		*buffer = NULL;
}
