#include "monty.h"
/**
 * pint - prints the value on the top of the stack
 * @top: pointer to the top of the list
 * @line_number: the line number at the file
 */
void pint(stack_t **top, unsigned int line_number)
{
	int a = 0;

	(void)line_number;
	if (top && *top)
		printf("%d\n", (*top)->n);
	a = 1;
}
