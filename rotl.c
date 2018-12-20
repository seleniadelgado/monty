#include "monty.h"

/**
  * rotl - rotates the stack to the top
  * @stack: double pointer to stack
  * @line_number: line number of the file
  */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tail, *head, *new_tail;
	(void)line_number;

	tail = info.tail;
	if (tail == NULL || (tail->prev == NULL && tail->next == NULL))
		return;

	head = *stack;

	new_tail = tail->prev;
	new_tail->next = tail->next;
	tail->next = head;
	tail->prev = head->prev;
	head->prev = tail;

	if (info.num_nodes == 2)
	{
		head->next = NULL;
		new_tail->prev = tail;
	}
	info.tail = new_tail;
	*stack = tail;
}

/**
  * rotr - changes format of data stack to queue and vice versa
  * @stack: double pointer to stack
  * @line_number: line number of the file
  */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *current, *temp;
	(void)line_number;

	current = *stack;
	while (current != NULL)
	{
		temp = current->next;
		current->next = current->prev;
		current->prev = temp;
		current = temp;
	}
	temp = *stack;
	*stack = info.tail;
	info.tail = temp;
}
