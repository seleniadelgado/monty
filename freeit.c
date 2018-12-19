#include "monty.h"
/**
 * freeit - frees the entire allocated memory.
 * @stack: stack to be freed.
 */
void freeit(stack_t **stack)
{
	stack_t *temp = *stack;
	stack_t *storage;

	while (temp != NULL)
	{
		storage = temp->next;
		free(temp);
		temp = storage;
	}
}
