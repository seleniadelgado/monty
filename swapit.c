#include "monty.h"
/**
 * swap - function that swaps the top two elements of the stack.
 * @stack: first stack to be swapped with stack beneath it.
 * @line_number: number of lines counted in file.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	stack_t *storage;
	int i;

	if (checkfortwo(stack) == 1)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	i = 0;
	printf("before while loop");
	while (temp != NULL)
	{
		printf("first in while");
		if (i == 2)
		{
			printf("first if");
			storage = temp->prev;/** make the storage previous node.*/
			storage = temp->next;/** storage is now next to temp*/
			temp->prev = NULL;/*makes temp point to null at the beginning*/
			storage->next = NULL;/*makes storage pt to NULL*/
		}
		else /** if there are more than 2 elements in the stack.*/
		{
			printf("in else");
			storage = temp->prev; /*placing previous node in strg*/
			temp->next = storage; /*moving storage to after temp */
			storage->prev = temp; /*moving temp to before storage */
			storage->next = NULL; /*making storage point to NULL */
		}
		temp = temp->next;
		i++;
	}
}
