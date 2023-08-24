#include "monty.h"
/**
 * push - this function is push an element into a stack
 * @top: pointer to the top of the list
 * @line_number: the data to push in stack
 */
void push(stack_t **top, unsigned int line_number)
{
	stack_t *node = NULL;

	(void)line_number;
	node = malloc(sizeof(stack_t));
	if (!node)
	{
		while (*top)
			pop(top, line_number);
		write(2, "Error: malloc failed\n", strlen("Error: malloc failed\n"));
		fclose(file);
		exit(EXIT_FAILURE);
	}
	node->prev = NULL;
	node->next = *top;
	*top = node;
}
