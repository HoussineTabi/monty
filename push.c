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
		fprintf(stderr, "Error: malloc failed\n");
		fclose(file);
		exit(EXIT_FAILURE);
	}
	if (*top == NULL)
	{
		node->prev = NULL;
		node->next = *top;
		*top = node;
	}
	else
	{
		node->prev = NULL;
		node->next = *top;
		(*top)->prev = node;
		(*top) = node;
	}
}
