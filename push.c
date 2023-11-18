#include "monty.h"

/**
 * push - Pushes an element onto the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number
 *
 * Description: If the argument is not an integer or if there is no argument,
 * prints an error message and exits with EXIT_FAILURE. If malloc fails,
 * prints an error message and exits with EXIT_FAILURE.
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *value_str = strtok(NULL, " \n");
	int value;
	stack_t *new_node = malloc(sizeof(stack_t));

	if (value_str == NULL || isdigit(value_str) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(value_str);

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;

	new_node->next = *stack;

	new_node->prev = NULL;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}

