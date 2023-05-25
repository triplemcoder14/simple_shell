#include "main.h"
/**
  * input_token_count - counts the amount of words the user inputs in getline
  * @buf: what the user inputs
  * Return: the amount of words the user has inputted
  */
int input_token_count(char *buf)
{
	int i, counter;

	i = counter = 0;
	if (buf == NULL)
		return (0);
	while (buf[i] == ' ' || buf[i] == '\n' || buf[i] == '\t')
		i++;
	if (buf[i] == '\0')
		return (0);
	while (buf[i] != '\0')
	{
		if ((buf[i] != ' ' && (buf[i + 1] == ' ' || buf[i + 1] == '\n')))
			counter++;
		i++;
	}
	return (counter);
}
