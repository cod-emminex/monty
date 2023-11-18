#include "monty.h"

/**
 * pall - Prints all values on the stack, starting from the top of the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number
 *
 * Description: If the stack is empty, does nothing.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	/* Unused variable - this is here to comply with the project requirements */
	(void)line_number;

	/* If the stack is empty, do nothing */
	if (tmp == NULL)
		return;

	(void)line_number;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
