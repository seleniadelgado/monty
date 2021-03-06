#include "monty.h"
info_t info  = {NULL, NULL, 0, NULL, 0};
/**
 * main - entry point for monty interpreter
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 (Success)
 */
int main(int argc, char *argv[])
{
	instruction_t opchecker[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", _div},
		{"mul", _mul},
		{"nop", nope},
		{"mod", mod},
		{"pchar", pchar},
		{"rotl", rotl},
		{"rotr", rotr},
		{"pstr", pstr},
		{"stack", stack},
		{"queue", queue},
		{NULL, NULL}
	};
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	return (perform_file(opchecker, argv[1]));
}

/**
  * perform_file - performs commands in a .m file
  * @opchecker: pointer to an array of structures of different opcodes
  * @input: input corresponding to the filename of the .m file
  * Return: 0 (Success)
  */
int perform_file(instruction_t *opchecker, char *input)
{
	FILE *opn;
	char *uop, *ptr = NULL;
	size_t n;
	stack_t *stack = NULL;
	unsigned int i, lnum = 0;

	opn = info.file = fopen(input, "r");
	if (opn == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", input);
		exit(EXIT_FAILURE);
	}
	while (getline(&ptr, &n, opn) != -1)
	{
		lnum++;
		info.buf = ptr;
		uop = strtok(ptr, DELIMITERS);
		if (uop == NULL || uop[0] == '#')
			continue;
		for (i = 0; opchecker[i].opcode != NULL; i++)
		{
			if (strcmp(uop, opchecker[i].opcode) == 0)
			{
				opchecker[i].f(&stack, lnum);
				break;
			}
		}
		if (opchecker[i].opcode == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", lnum, uop);
			freeit(&stack);
			exit(EXIT_FAILURE);
		}
	}
	info.buf = ptr;
	freeit(&stack);
	exit(EXIT_SUCCESS);
}
