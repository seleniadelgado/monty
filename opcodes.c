#include "monty.h"

/**
  * pint - prints the value at the top of the stack
  * @stack: double pointer to an array of structures
  * @line_number: line number of file
  */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *tail;

	tail = *stack;
	if (tail == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (tail->next != NULL)
		tail = tail->next;
	printf("%d\n", tail->n);
}

/**
  * pop - removes the top element of the stack
  * @stack: double pointer to an array of structures
  * @line_number: line number of file
  */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tail;

	tail = *head;
	if (head == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (tail->next != NULL)
		tail = tail->next;
	if (tail->prev == NULL)
		*stack = NULL;
	else
		tail->prev->next = tail->next;
	free(tail);
}
