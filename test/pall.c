#include "monty.h"
/**
 * pall - prints the element of a stack
 * @top: the top of the stack
 * @line_number: the number of the line
 */
void pall(stack_t **top, unsigned int line_number)
{
	stack_t *head = *top;
	char c = '\n';

	(void)line_number;
	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}
