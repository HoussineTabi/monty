#include "monty.h"
/**
 * swap - swaps the top two elements of the stack
 * @top: the top of the list
 * @line_number: the line number
 */

void swap(stack_t **top, unsigned int line_number)
{
	stack_t *tmp = NULL;
        char str_n_of_line[20];

        if (!top || *top == NULL || (*top)->next == NULL)
        {
                sprintf(str_n_of_line, "%u", line_number);
                write(2, "L", strlen("L"));
                write(2, str_n_of_line, strlen(str_n_of_line));
                write(2, ": can't swap, stack too short\n", strlen(": can't swap, stack too short\n"));
                exit(EXIT_FAILURE);
        }
	tmp = (*top)->next;
	(*top)->next = (*top)->next->next;
	tmp->next = *top;
	*top = tmp;
}
