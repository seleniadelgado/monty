#include "monty.h"
/**
 * push - function that pushes an element to the stack.
 * @stack: element that is added.
 * @line_number: number of lines in file.
 */
void push(stack_t **stack, unsigned int line_number);
{
	stack_t *temp = *stack;
	stack_t *new;

	if (temp == NULL)
		return (NULL);
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);
	new = new->n;
	if (temp == NULL)
	{
		new->prev = NULL;
		new->next = NULL;
		new = stack;
	}
	while (temp->next != NULL)
	{
		temp = temp->next;
		new->prev = temp;
		new->next = NULL;
		*stack = new;
	}
}
/**
 * pall - function that prints all the values on the stack, starting from the
 * top of the stack.
 *@stack: stack that integers are being printed from.
 *@line_number: number of lines in file.
 */
void pall(stack_t **stack, unsigned int line_number);
{
	stack_t *temp = *stack;

	if (temp == NULL)
		return;
	while (temp != NULL)
	{
		fprintf("%d ", stack->n);
		temp = temp->next;
	}
}
