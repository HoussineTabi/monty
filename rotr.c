#include "monty.h"
/**
 * rotl - prints the element of a stack
 * @top: the top of the stack
 * @line_number: the number of the line
 */
void rotr(stack_t **top, unsigned int line_number)
{
	stack_t *head = *top;
	int n;

	if (!head || !head->next)
		return;
	(void)line_number;

	while (head->next)
	{
		head = head->next;
	}
	n = head->n;
	while (head->prev)
	{
		head->n = head->prev->n;
		head = head->prev;
	}
	head->n = n;
}
