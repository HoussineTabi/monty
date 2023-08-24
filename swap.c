#include "monty.h"
/**
 * swap - swaps the top two elements of the stack
 * @top: the top of the list
 * @line_number: the line number
 */

void swap(stack_t **top, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (!top || *top == NULL || (*top)->next == NULL)
	{

		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	tmp = (*top)->next;
	(*top)->next = (*top)->next->next;
	tmp->next = *top;
	*top = tmp;
}
