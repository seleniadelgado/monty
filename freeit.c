#include "monty.h"
/**
 * freeit - frees the entire allocated memory.
 * @stack: stack to be freed.
 */
void freeit(stack_t **stack)
{
	stack_t *temp = *stack;
	stack_t *storage;

	while (temp != NULL && temp->prev != NULL)
		temp = temp->prev;
	while (temp != NULL)
	{
		storage = temp->next;
		free(temp);
		temp = storage;
	}
	if (info.file != NULL)
		fclose(info.file);
	if (info.buf != NULL)
		free(info.buf);
}
