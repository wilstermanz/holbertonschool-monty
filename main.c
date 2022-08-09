#include "monty.h"

/*instruction_t commands[] = {
	{"push", push},		{"pall", pall},
	{"pint", pint},		{"pop", swap},
	{"add", add},		{"nop", nop},
	{NULL, NULL}
};*/

int main(int argc, char *argv[])
{
	unsigned int line_number = 0;
	char *buffer = NULL, *token;
	size_t buffsize = 0;
	FILE *fp;
	int i = 0;

//	if (argc != 2)
//		print_error(1, argv[0], line_number, NULL);

	fp = fopen(argv[1], "r");

//	if (file == -1)
//		print_error(2, argv[0], line_number, NULL);
	args = malloc(sizeof(char *) * 2);

	while (getline(&buffer, &buffsize, fp) != EOF)
	{
		line_number++;
		parse(buffer);
	}

	fclose(fp);
	free(args);

	return (EXIT_SUCCESS);
}
