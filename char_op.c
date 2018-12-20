#include "monty.h"

/**
  * pchar - prints char at the top of the stack
  * @stack: double pointer to stack
  * @line_number: line number
  */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *tail;
	int value;
	(void)stack;

	tail = info.tail;
	if (tail == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = tail->n;
	if (value < 0 || value > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%c\n", value);
}
