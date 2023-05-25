#include "main.h"
/**
 * input_parserator - parese the input
 * @input_buffer: buffer that holds the input
 * Return: returns the input, parsed
 */
char *input_parserator(char *input_buffer)
{
	char *parsed_input;
	int i;

	parsed_input = _strdup(input_buffer);
	for (i = 0; parsed_input[i] != '\0'; i++)
	{
		while (input_buffer[i] == ' ')
			i++;
		parsed_input = &input_buffer[i];
	}
	free(input_buffer);
	return (parsed_input);

}
