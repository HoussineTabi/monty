#include "monty.h"
FILE *file = NULL;
/**
 *open_file - this function open a file
 *@str: parameter pointer
 *@mod: parameter pointer
 *Return: return pointer to file
 */
FILE *open_file(char *str, char *mod)
{
	file = fopen(str, mod);

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", str);
		exit(EXIT_FAILURE);
	}
	return (file);
}
/**
 *regular_errror - this function print regular error
 *@count_line: parameter unsigned long
 *@line: parameter pointer
 */
void regular_errror(unsigned int count_line, char *line)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", count_line, line);
}
/**
 *push_error - this function print an error
 *@count_line: parameter string
 */
void push_error(unsigned int count_line)
{
	fprintf(stderr, "L%u: usage: push integer\n", count_line);
	exit(EXIT_FAILURE);
}
/**
 *error_n_arguments - this function print an error
 */
void error_n_arguments(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
/**
 * main - reads a line from a monty file
 * @ac: argument counter
 * @arv: argument vecture
 * Return: 0 in success and specified error value in failed
 */
int main(int ac, char **arv)
{
	unsigned int count_line = 0, i = 0;
	char *arg1 = NULL, *arg2 = NULL, buffer_file[1024];
	stack_t *top = NULL;
	size_t size = 1024;

	if (ac != 2)
		error_n_arguments();
	file = open_file(arv[1], "r");
	while (fgets(buffer_file, size, file) != NULL)
	{
		count_line++;
		if (buffer_file[0] == '\n')
			continue;
		arg1 = strtok(buffer_file, " \t\n");
		if (arg1 == NULL || arg1[0] == '#')
			continue;
		arg2 = strtok(NULL, " \t\n");
		if (!check_fun(&top, arg1, arg2, count_line))
		{
			regular_errror(count_line, arg1);
			while (top)
				pop(&top, count_line);
			fclose(file);
			exit(EXIT_FAILURE);
		}
		arg1 = NULL, arg2 = NULL;
		for (i = 0; i < 1024; i++)
			buffer_file[i] = '\0';
	}
	while (top)
		pop(&top, count_line);
	fclose(file);
	return (0);
}
