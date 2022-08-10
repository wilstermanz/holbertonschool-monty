#include "monty.h"

char **parse(char *buffer)
{
	char **args;
	char *token;
	char *strCpy = strdup(buffer);
	int count = 0, i = 0;

	args = malloc(sizeof(*args) * (count + 1));
	if (!args)
	{
		free(args);
		exit(1);
	}
	count = 0;
	token = strtok(strCpy, " ");
	while (token != NULL)
	{
		args[count] = strdup(token);
		token = strtok(NULL, " ");
		count++;
	}

	free(buffer);
	free(strCpy);
	free(token);
	return (args);
}
