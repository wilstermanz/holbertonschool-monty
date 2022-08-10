#include "monty.h"

instruction_t commands[] = {
	{"push", push},		{"pall", pall},
//	{"pint", pint},		{"pop", swap},
//	{"add", add},		{"nop", nop},
	{NULL, NULL}
};

int main(int argc, char *argv[])
{
	unsigned int error_flag = 0;
	char *buffer = NULL;
	size_t buffsize = 0;
	FILE *fp;
	stack_t *stack = NULL;

	if (argc != 2)
		error_flag = print_error(1, argv[1], 0, NULL);

	fp = fopen(argv[1], "r");
	if (fp == NULL)
		error_flag = print_error(2, argv[1], 0, NULL);

	while ((getline(&buffer, &buffsize, fp) != EOF) && (error_flag == 0))
	{
		error_flag = instruction_checker(&buffer, &stack, argv[1]);
	}

	free_stack_t(stack);
	free(buffer);
	fclose(fp);
	if(error_flag == 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int instruction_checker(char **buffer, stack_t **stack, char *file)
{
	char *opcode = NULL;
	unsigned int  line_number = 0, i, error_flag = 0;

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
			error_flag = print_error(3, file, line_number, opcode);
		}

		free(*buffer);
		*buffer = NULL;

		return (error_flag);
}
