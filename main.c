#include "monty.h"

instruction_t commands[] = {
	{"push", push},		{"pall", pall},
//	{"pint", pint},		{"pop", swap},
//	{"add", add},		{"nop", nop},
	{NULL, NULL}
};

int main(int argc, char *argv[])
{
	unsigned int line_number = 0, i, error_flag = 0;
	char *buffer = NULL, *opcode = NULL;
	size_t buffsize = 0;
	FILE *fp;
	stack_t *stack = NULL;
//	if (argc != 2)
//		error_flag = print_error(1, argv[0], line_number, opcode);

	fp = fopen(argv[1], "r");
//	if (file == -1)
//		error_flag = print_error(2, argv[0], line_number, opcode);

	while (getline(&buffer, &buffsize, fp) != EOF)
	{
		line_number++;
		opcode = strtok(buffer, " \n");
		for (i = 0; commands[i].opcode; i++)
		{
			if (strcmp(opcode, commands[i].opcode) == 0)
			{
				commands[i].f(&stack, line_number);
				break;
			}
		}
		if (commands[i].opcode == NULL)
		{
			printf("Command not found\n");
//			error_flag = print_error(3, argv[0], line_number, opcode);
		}
		else
		{
			printf("line %d: ",  line_number);
			printf("opcode %s ",  opcode);
			printf("value %i\n", stack->n);
		}

		free(buffer);
		buffer = NULL;
	}

	free_stack_t(stack);
	free(buffer);
	fclose(fp);
	if(error_flag == 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
