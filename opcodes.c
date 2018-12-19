#include "monty.h"

/**
  * pint - prints the value at the top of the stack
  * @stack: double pointer to an array of structures
  * @line_number: line number of file
  */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *tail;
	extern char *buf;

	tail = *stack;
	if (tail == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		freeit(stack);
		free(buf);
		exit(EXIT_FAILURE);
	}
	while (tail->next != NULL)
		tail = tail->next;
	printf("%d\n", tail->n);
}

/**
  * pop - removes the top element of the stack
  * @stack: double pointer to doubly linked list
  * @line_number: line number of file
  */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tail;
	extern char *buf;

	tail = *stack;
	if (tail == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		freeit(stack);
		free(buf);
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

/**
  * add - adds the top two elements of the stack
  * @stack: double pointer to doubly linked list
  * @line_number: line number of file
  */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	int sum;
	extern char *buf;

	node = *stack;
	if (checkfortwo(stack))
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		freeit(stack);
		free(buf);
		exit(EXIT_FAILURE);
	}
	while (node->next != NULL)
		node = node->next;
	sum = node->prev->n + node->n;
	node->prev->n = sum;
	node->prev->next = node->next;
	free(node);
}

/**
  * sub - subtracts the top element from the second top element of the stack
  * @stack: double pointer to doubly linked list
  * @line_number: line number of file
  */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	int sub;
	extern char *buf;

	node = *stack;
	if (checkfortwo(stack))
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free(buf);
		freeit(stack);
		exit(EXIT_FAILURE);
	}
	while (node->next != NULL)
		node = node->next;
	sub = node->prev->n - node->n;
	node->prev->n = sub;
	node->prev->next = node->next;
	free(node);
}

/**
  * _div - divides the second top element of the stack by the top element
  * @stack: double pointer to doubly linked list
  * @line_number: line number of file
  */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	int div;
	extern char *buf;

	node = *stack;
	if (checkfortwo(stack))
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		freeit(stack);
		free(buf);
		exit(EXIT_FAILURE);
	}
	while (node->next != NULL)
		node = node->next;
	if (node->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		freeit(stack);
		free(buf);
		exit(EXIT_FAILURE);
	}
	div = node->prev->n / node->n;
	node->prev->n = div;
	node->prev->next = node->next;
	free(node);
}
