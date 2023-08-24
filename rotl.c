#include "monty.h"
/**
 * rotl - prints the element of a stack
 * @top: the top of the stack
 * @line_number: the number of the line
 */
void rotl(stack_t **top, unsigned int line_number)
{
	stack_t *head = *top;
	int n;

	if (!head || !head->next)
		return;
	(void)line_number;
	n = head->n;
	while (head->next && head)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
	(*top)->n = head->n;
	head->n = n;

}
