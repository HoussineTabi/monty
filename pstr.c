#include "monty.h"
/**
 * pstr - prints the element of a stack
 * @top: the top of the stack
 * @line_number: the number of the line
 */
void pstr(stack_t **top, unsigned int line_number)
{
	stack_t *head = *top;

	(void)line_number;
	while (head)
	{
		if (head->n > 0 && head->n <= 127)
			putchar(head->n);
		else
			break;
		head = head->next;
	}
	putchar('\n');
}
