#include "monty.h"

/**
 * push - this function is push an element into a stack
 * @top: pointer to the top of the list
 * @data: the data to push in stack
 */
void push(stack_t **top, unsigned int data)
{
	stack_t *node = NULL;

	node = malloc(sizeof(stack_t));
	if (!node)
	{
		perror(" ");
		exit(EXIT_FAILURE);
	}
	node->prev = NULL;
	node->next = *top;
	*top = node;
}
