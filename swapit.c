/**
 * swap - function that swaps the top two elements of the stack.
 * @stack: first stack to be swapped with stacks beneath it.
 * @line_number: number of lines counted in file.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	stack_t *storage;

	if (stack < 2 );/**find the best way to do this */
	fprintf(stderr, "L%u: can't swap, stack too short", line_number);
	while (temp != NULL)
	{
		temp = temp->next; /** iterator */
		storage = temp->prev; /*placing previous node in strg*/
		temp->next = storage; /*moving storage to after temp */
		storage->prev = temp; /*moving temp to before storage */
		storage->next = NULL; /*making storage point to NULL */
	}
/* think about if there is only two node to swap. */


}
