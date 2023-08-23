#include "monty.h"

/**
 * check_fun - check of the firs argument is a function
 * @top: pointer to the top of the stack
 * @arg1: the first argument opcode
 * @arg2: the second argument
 * @line_number: the line number
 * Return: 1 if success and 0 else
 */
int check_fun(stack_t **top, char *arg1, char *arg2, unsigned int line_number)
{
	instruction_t fun_table[] = {
		{"push", push},
		{"pop", pop},
		{"pall", pall},
		{"pint", pint},
		{NULL, NULL}
	};
	int i;

	for (i = 0; fun_table[i].opcode; i++)
	{
		if (!strcmp(fun_table[i].opcode, arg1))
		{
			if (i >= 1)
			{
				if (arg2 == NULL || sizeof(arg2) == 0)
				{
					fun_table[i].f(top, line_number);
					return (1);
				}
				return (0);
			}
			else if (arg2 == NULL || !_isdigit(arg2))
			{
				while (*top)
					pop(top, line_number);
				push_error(line_number);
				break;
			}
			fun_table[i].f(top, line_number);
			(*top)->n = atoi(arg2);
			return (1);

		}
	}
	return (0);
}
/**
 * _isdigit - checks if a string is a digit
 * @str: the string to check
 * Return: 1 if the string is digit and 0 else
 */
int _isdigit(char *str)
{
	if (str == NULL)
		return (0);
	while (*str)
	{
		if (*str > 57 || *str < 48)
			return (0);
		str++;
	}
	return (1);
}
