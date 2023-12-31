#include "monty.h"

instruction_t fun_table[] = {
{"push", push}, {"nop", nop}, {"pop", pop}, {"add", add}, {"sub", sub},
{"pall", pall}, {"pint", pint}, {"swap", swap}, {"div", divs}, {"rotl", rotl}
, {"mul", mul}, {"mod", mod}, {"pchar", pchar}, {"pstr", pstr}, {"rotr", rotr}
, {NULL, NULL}
};
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
	int i, sign = 1;

	for (i = 0; fun_table[i].opcode; i++)
	{
		if (!strcmp(fun_table[i].opcode, arg1))
		{
			if (i > 1)
			{
				fun_table[i].f(top, line_number);
				return (1);
			}
			if (i == 1)
				return (1);
			else if (arg2 == NULL || !_isdigit(arg2 + 1)
				       || (arg2[0] != '-' && (arg2[0] > '9')
					&& (arg2[0] < '0')))
			{
				while (*top)
					pop(top, line_number);
				push_error(line_number);
			}
			fun_table[i].f(top, line_number);
			if (sign == -1 && arg2[0] == '-')
				(*top)->n = -1 * atoi(arg2), sign = -1, arg2 = &arg2[1];
			if (strlen(arg2) > strlen("2147483647"))
				push_error(line_number);
			(*top)->n = sign * atoi(arg2);
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
