#include "monty.h"

instruction_t commands[] = {
	{"push", push},		{"pall", pall},
//	{"pint", pint},		{"pop", swap},
//	{"add", add},		{"nop", nop},
	{NULL, NULL}
};

int main(int argc, char *argv[])
{
	unsigned int line_number = 0;
	char *buffer = NULL, *opcode;
	size_t buffsize = 0;
	FILE *fp;
	int i;
	stack_t *stack = malloc(sizeof(stack_t *));

//	if (argc != 2)
//		print_error(1, argv[0], line_number, NULL);

	fp = fopen(argv[1], "r");
//	if (file == -1)
//		print_error(2, argv[0], line_number, NULL);

	while (getline(&buffer, &buffsize, fp) != EOF)
	{
		line_number++;
		opcode = strtok(buffer, " \n");
		for (i = 0; commands[i].opcode; i++)
		{
			if (strcmp(opcode, commands[i].opcode) == 0)
			{
				commands[i].f(&stack, line_number);
			}
		}
		printf("line %d: ",  line_number);
		printf("opcode %s ",  opcode);
		printf("value %i\n", stack->n);
		free(buffer);
		buffer = NULL;
	}

	free(buffer);
	free(stack);
	fclose(fp);

	return (EXIT_SUCCESS);
}
