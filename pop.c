#include "monty.h"
/**
 * pop - pops an element at the top of the stack
 * @top: the top of the stack
 * @line_number: the number of line in the file
 */
void pop(stack_t **top, unsigned int line_number)
{
	stack_t *node = NULL;

	if (!top || *top == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	else
	{
		line_number--;
		node = *top;
		*top = (*top)->next;
		free(node);
	}
}
