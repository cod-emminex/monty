#include "monty.h"

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Description: Opens a file containing Monty byte codes, and executes them.
 * If an error occurs, prints an error message and exits with EXIT_FAILURE.
 *
 * Return: EXIT_SUCCESS on success, or EXIT_FAILURE on failure
 */


int main(int argc, char *argv[]);
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char *opcode;
	int value;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, file)) != -1)
	{
		opcode = strtok(line, " \n");
		value = atoi(strtok(NULL, " \n"));

		if (strcmp(opcode, "push") == 0)
		{
			push(&stack, value);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(&stack, value);
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", value, opcode);
			exit(EXIT_FAILURE);
		}
	}

	free(line);
	fclose(file);

	return (0);
}
