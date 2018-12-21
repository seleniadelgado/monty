#ifndef MONTY_H
#define MONTY_H

#define DELIMITERS " \n\t\r"

/* C Standard Library */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
/* Structure Prototypes */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
  * struct info_s - stores basic information about the program
  * @file: file pointer
  * @buf: buffer storing getline string
  * @num_nodes: number of nodes
  * @tail: tail of stack
  * @queue_on: indicates whether queue mode is on (1 is on)
  *
  * Description: structure that holds important elements of the Monty program
  */
typedef struct info_s
{
	FILE *file;
	char *buf;
	size_t num_nodes;
	stack_t *tail;
	char queue_on;
} info_t;

extern info_t info;

/* Function Definitions for Opcodes */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void nope(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void pre_rotr(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void stack(stack_t **stack, unsigned int);
void queue(stack_t **, unsigned int);
void switch_data(stack_t **, unsigned int);

/* Function Definitions */
int str_int(char *str);
int checkfortwo(stack_t **stack);
int perform_file(instruction_t *, char *);
void freeit(stack_t **stack);
int _atoi(stack_t **, unsigned int, char *);
#endif
