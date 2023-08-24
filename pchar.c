#include "monty.h"
/**
 * pchar - prints the element of a stack
 * @top: the top of the stack
 * @line_number: the number of the line
 */
void pchar(stack_t **top, unsigned int line_number)
{
	stack_t *head = *top;

	if (!head)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	if (head->n >= 0 && head->n <= 126)
	{
		putchar(head->n);
		putchar('\n');
	}
	else
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		fclose(file);
		exit(EXIT_FAILURE);
	}
}
