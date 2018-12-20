#include "monty.h"
/**
 * pstr - prints the string at the top of the stack, followed by a new line.
 * @stack: to be iterated through.
 * @line_number: lines counted.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = info.tail;
	int string;

	(void)stack;
	(void)line_number;
	while (temp != NULL)
	{
		string = temp->n;
		if ((string == 0) || (string > 127) || (string < 0))
			break;
		printf("%c", string);
		temp = temp->prev;
	}
	printf("\n");

}
