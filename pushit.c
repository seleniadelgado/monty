#include "monty.h"

/**
 * push - function that pushes an element to the stack.
 * @stack: element that is added.
 * @line_number: number of lines in file.
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = info.tail;
	stack_t *new;
	int n;
	char *arg;
	(void)stack;

	arg = strtok(NULL, DELIMITERS);
	if (str_int(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		freeit(stack);
		exit(EXIT_FAILURE);
	}
	n = atoi(arg);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		freeit(stack);
		exit(EXIT_FAILURE);
	}
	info.num_nodes++;
	new->n = n;
	new->next = NULL;
	if (temp == NULL)
	{
		new->prev = NULL;
		*stack = new;
		info.tail = new;
	}
	else
	{
		new->prev = temp;
		temp->next = new;
		info.tail = new;
	}
}
/**
 * pall - function that prints all the values on the stack, starting from the
 * top of the stack.
 * @stack: stack that integers are being printed from.
 * @line_number: number of lines in file.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;
	(void)stack;

	temp = info.tail;
	if (temp == NULL)
		return;
	while (temp != NULL)
	{
		fprintf(stdout, "%d\n", temp->n);
		temp = temp->prev;
	}
}
