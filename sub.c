#include "monty.h"
/**
 * sub - adds the two top elements of the stackc
 * @top: the top of the stack
 * @line_number: the line number in the monty file
 */
void sub(stack_t **top, unsigned int line_number)
{
	if (top == NULL || *top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	(*top)->next->n = (*top)->next->n - (*top)->n;
	pop(top, line_number);
}
