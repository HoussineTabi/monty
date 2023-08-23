#include "monty.h"
#include <unistd.h>
#include <stdio.h>

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
	FILE *file = NULL;
	stack_t *top = NULL;
	size_t size = 1024;

	if (ac != 2)
		exit(EXIT_FAILURE);
	file = fopen(arv[1], "r");
	if (!file)
	{
		write(2, "file not found", sizeof("file not found"));
		exit(EXIT_FAILURE);
	}
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
		pop(&top);
	fclose(file);
	return (0);
}
