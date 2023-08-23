#include "monty.h"
int checkline(char **line)
{
	char *dupline = _strdup(*line);
	char *str[3];
	const char *push = "push";
	const char *pall = "pall";
	int i = 0, num;

	str[i] = strtok(dupline," \t");

	while (str[i])
	{
		i++;
		str[i] = strtok(NULL, " \t");
	}

	if (i == 0)
	{

		free(dupline);
		return (1);
	}
	if (!strcmp(str[0], pall))
	{
		free(dupline);
		return (1);
	}
	else if (!strcmp(str[0], push))
	{
		if (str[1] == NULL)
		{
			free(dupline);
			return (2);
		}
		num = atoi(str[1]);
		if (num == 0  && (str[1][0] != '0'))
		{
			free(dupline);
			return (2);
		}
		free(dupline);
		return (1);
	}
	else
	{

		free(dupline);
		return (0);
	}
}
