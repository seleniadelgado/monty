#include "monty.h"
/**
 * mulit - function that multiples the second top element of the stack with the
 * top element of the stack.
 * @stack: stack of which we will multiply the last two nodes of.
 * @line_number: lines counted in stack.
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int i = line_number;
	int result;
	int a;
	int b;

	if (checkfortwo(stack) == 1)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", i);
		exit(EXIT_FAILURE);
	}
	while ((temp != NULL) && (temp->next != NULL))
	{
		temp = temp->next;
	}
	a = temp->n;
	b = temp->prev->n;
	result = (a * b);
	temp->prev->n = result;
	temp->prev->next = NULL;
	free(temp);
}
