#include "monty.h"

/**
 * Error codes - This code is passed into perror to define which error code to print
 * 
 * 1 - Used if user does not give any file, or more than one arg to program.
 * Prints "USAGE: monty file" followed by new line,
 * and exits with status EXIT_FAILURE.
 * 
 * 2 - Used if it is not possible to open file.
 * Prints "Error: Can't open file <file>", followed by a new line,
 * and exits with the status EXIT_FAILURE.
 * 
 * 3 - Used if the file contains an invalid instruction.
 * Prints the error message "L<line_number>: unknown instruction <opcode>"",
 * followed by a new line, and exits with the status EXIT_FAILURE.
 * 
 * 4 - Used if malloc fails.
 * Prints the error message "Error: malloc failed",
 * followed by a new line, and exits with status EXIT_FAILURE.
 * 
 * print_error returns 1 on succcess
 */

int print_error(unsigned int error_code, char *file, unsigned int line_number, char *opcode)
{
	switch(error_code)
	{
		case 1 :
			fprintf(stderr, "USAGE: monty file\n");
			exit (EXIT_FAILURE);
		case 2 :
			fprintf(stderr, "Error: Can't open file %s\n", file);
			exit (EXIT_FAILURE);
		case 3 :
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			break;
		case 4 :
			fprintf(stderr, "Error, malloc failed");
			break;
	}
	return (1);
}
