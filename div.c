#include "monty.h"
/**
 * divs - division the two top elements of the stackc
 * @top: the top of the stack
 * @line_number: the line number in the monty file
 */
void divs(stack_t **top, unsigned int line_number)
{
	if (top == NULL || *top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	if ((*top)->next->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		fclose(file);
		exit(EXIT_FAILURE);
	}

	(*top)->next->n = (*top)->n / (*top)->next->n;
	pop(top, line_number);
}
