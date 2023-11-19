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
	char *value_str;
	int value;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[0], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		opcode = strtok(line, " \n");
		if (opcode == NULL)
			continue;

		if (strcmp(opcode, "push") == 0)
		{
			value_str = strtok(NULL, " \n");
			if (value_str == NULL || isdigit(value_str) == 0)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			value = atoi(value_str);
			push(&stack, value);
			if (strtok(NULL, " \n") != NULL)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			if (strtok(NULL, " \n") != NULL)
			{
				fprintf(stderr, "L%d: usage: pall\n", line_number);
				exit(EXIT_FAILURE);
			}
			pall(&stack, line_number);
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number,
					opcode);

			exit(EXIT_FAILURE);
		}
		free(line);
		fclose(file);
	}
	return (0);
}
