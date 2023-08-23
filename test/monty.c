#include "monty.h"
#include <unistd.h>
#include <stdio.h>

/**
 * main - reads a line from a monty file
 * @ac: argument counter
 * @arv: argument vecture
 * Return: 0 in success and specified error value in failed
 */
FILE *open_file(char *str, char *mod)
{
	FILE *file_stream = fopen(str, mod);

	if (file_stream == NULL)
	{
		write(2, "Error: Can't open file ", sizeof("Error: Can't open file "));
		write(2, str, strlen(str));
		write(2, "\n", sizeof("\n"));
		exit(EXIT_FAILURE);
	}
	return (file_stream);
}
void regular_errror(char *str_n_of_line, char *line)
{
	write(2, "L", sizeof("L"));
	write(2, str_n_of_line, strlen(str_n_of_line));
	write(2, ": unknown instruction ", sizeof(": unknown instruction "));
	write(2, line, strlen(line));
	write(2, "\n", 2);
}
void push_error(char *str_n_of_line)
{
	write(2, "L",2);
	write(2, str_n_of_line, strlen(str_n_of_line));
	write(2, ": usage: push integer\n",sizeof(": usage: push integer\n"));
	exit(EXIT_FAILURE);
}
void error_n_arguments()
{
	write(2, "USAGE: monty file\n",sizeof("USAGE: monty file\n"));
	exit(EXIT_FAILURE);
}
int main(int ac, char **arv)
{
	unsigned int count_line = 0, i = 0;
	char *arg1 = NULL, *arg2 = NULL, buffer_file[1024];
	FILE *file = NULL;
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
		arg1 = strtok(buffer_file, " \n");
		if (arg1 == NULL)
			continue;
		arg2 = strtok(NULL, " \n");
		if (!check_fun(&top, arg1, arg2, count_line))
		{
			perror("error in line");
			while (top)
				pop(&top, count_line);
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
