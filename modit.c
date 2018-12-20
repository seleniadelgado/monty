#include "monty.h"
/**
 * mod - function that divides the second top element of the stack by the top
 * element of the stack.
 * @stack: stack of which we will be divind the top and second top elements.
 * @line_number: the line number counter where an error occurs.
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = info.tail;
	int first;
	int second;
	int result;
	unsigned int i = line_number;

	if (info.num_nodes < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", i);
		freeit(stack);
		exit(EXIT_FAILURE);
	}
	second = temp->prev->n;
	first = temp->n;
	if (first == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		freeit(stack);
		exit(EXIT_FAILURE);
	}
	result = second % first;
	temp->prev->n = result;
	temp->prev->next = NULL;
	free(temp);
}
