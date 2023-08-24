#include "monty.h"
/**
 * pint - prints the value on the top of the stack
 * @top: pointer to the top of the list
 * @line_number: the line number at the file
 */
void pint(stack_t **top, unsigned int line_number)
{
	char str_number[20];

	sprintf(str_number, "%u", line_number);
	if (top && *top)
		printf("%d\n", (*top)->n);
	else
	{
		write(2, "L", strlen("L"));
		write(2, str_number, strlen(str_number));
		write(2, ": can't pint, stack empty", strlen(": can't pint, stack empty"));
		while (*top)
			pop(top, line_number);
		fclose(file);
		exit(EXIT_FAILURE);
	}
}
