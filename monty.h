#ifndef MONTY_H
#define MONTY_H

/* Libraries */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Global Variable */

/* Function prototypes */

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
//void pint(stack_t **stack, unsigned int line_number);
//void pop(stack_t **stack, unsigned int line_number);
//void swap(stack_t **stack, unsigned int line_number);
//void add(stack_t **stack, unsigned int line_number);
//void nop(stack_t **stack, unsigned int line_number);
char **parse(char *buffer);
int print_error(unsigned int error_code, char *file, unsigned int line_number, char *opcode);
void free_stack_t(stack_t *stack);

#endif

/**
 * Error codes - This code is passed into print_error to define which error code to print
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
