#include "monty.h"
#define DELIMETERS " \n\t"
/**
 * monty - main file for interpreter.
 *
 */
int main (int argc, char *argv[])
{
	FILE *opn;
	char *ptr = NULL;
	size_t n;
	char *uop;
	stack_t *stack;
	unsigned int lnum = 0;
	unsigned int i;
	instruction_t opchecker[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"add", add},
		{"sub", sub},
		{NULL, NULL}
	};
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	opn = fopen(argv[1], "r");
	if (opn == NULL)
	{
		fprintf(stderr, "Error: Can't open file <file>\n");
		exit(EXIT_FAILURE);
	}
	while (getline(&ptr, &n, opn) != -1)
	{
		lnum++;
		uop = strtok(ptr, DELIMETERS);
		for (i = 0; opchecker[i].opcode != NULL; i++)
		{
			if (strcmp(uop, opchecker[i].opcode) == 0)
			    opchecker[i].f(&stack, line_number);
		}
		if (opchecker[i].opcode == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", lnum, uop);
			exit(EXIT_FAILURE);
		}
	}
	exit(EXIT_SUCCESS);
}
