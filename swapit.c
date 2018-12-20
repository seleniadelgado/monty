#include "monty.h"
/**
 * swap - function that swaps the top two elements of the stack.
 * @stack: first stack to be swapped with stack beneath it.
 * @line_number: number of lines counted in file.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = info.tail;
	stack_t *storage;

	if (info.num_nodes < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		freeit(stack);
		exit(EXIT_FAILURE);
	}
	if (info.num_nodes == 2)
	{
		storage = temp->prev;/** make the storage previous node.*/
		storage->prev = temp;/** storage is now next to temp*/
		temp->next = storage;
		temp->prev = NULL;/*makes temp point to null at the beginning*/
		storage->next = NULL;/*makes storage pt to NULL*/
		*stack = temp;
		info.tail = storage;
	}
	else
	{
		/** if there are more than 2 elements in the stack.*/
		storage = temp->prev; /*placing previous node in strg*/
		storage->prev->next = temp;
		temp->prev = storage->prev;
		storage->prev = temp; /*moving temp to before storage */
		storage->next = temp->next; /*making storage point to NULL */
		temp->next = storage; /*moving storage to after temp */
		info.tail = storage;
	}
}
