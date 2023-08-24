#include "monty.h"
/**
 * pop - pops an element at the top of the stack
 * @top: the top of the stack
 * @line_number: the number of line in the file
 */
void pop(stack_t **top, unsigned int line_number)
{
	stack_t *node = NULL;
	char str = ": can't pop an empty stack\n";
	char str_n_of_line[20];

	if (!top || *top == NULL)
	{
		sprintf(str_n_of_line, "%u", line_number);
		write(2, "L", strlen("L"));
		write(2, str_n_of_line, strlen(str_n_of_line));
		write(2, str, strlen(str));
		exit(EXIT_FAILURE);
	}
	else
	{
		line_number--;
		node = *top;
		*top = (*top)->next;
		free(node);
	}
}
