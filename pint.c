#include "monty.h"
/**
 * pint - prints the value on the top of the stack
 * @top: pointer to the top of the list
 * @line_number: the line number at the file
 */
void pint(stack_t **top, unsigned int line_number)
{
	if (top && *top)
		fprintf(stdout, "%d\n", (*top)->n);
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		while (*top)
			pop(top, line_number);
		fclose(file);
		exit(EXIT_FAILURE);
	}
}
