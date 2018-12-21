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
	stack_t *tail, *head, *mid;
	(void)line_number;

	tail = info.tail;
	if (info.num_nodes < 2)
		return;
	head = *stack;
	mid = head->next;
	mid->prev = head->prev;
	head->prev = tail;
	head->next = tail->next;
	tail->next = head;
	*stack = mid;
	info.tail = head;
}

/**
  * switch_data - changes format of data stack to queue and vice versa
  * @stack: double pointer to stack
  * @line_number: line number of the file
  */
void switch_data(stack_t **stack, unsigned int line_number)
{
	stack_t *current, *temp;
	(void)line_number;

	current = *stack;
	if (current != NULL)
	{
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
}

/**
  * stack - changes format of data to stack
  * @stack: double pointer to stack
  * @line_number: line number of the file
  */
void stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	/* if (info.queue_on == 1) */
	/*	switch_data(stack, line_number); */
	info.queue_on = 0;
}

/**
  * queue - changes format of data to stack
  * @stack: double pointer to stack
  * @line_number: line number of the file
  */
void queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	/* if (info.queue_on == 0) */
	/* switch_data(stack, line_number); */
	info.queue_on = 1;
}
