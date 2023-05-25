#include "main.h"
/**
 * print_env_list - prints the contents of the env variables linked list
 * @h: pointer to environmental variable linked list
 * Return: number of nodes
 */
size_t print_env_list(const env_t *h)
{
	size_t nodes = 0;
	const env_t *traverser = h;

	while (traverser != NULL)
	{
		_write(traverser->key);
		_write("=");
		_write(traverser->value);
		_write("\n");
		traverser = traverser->next;
		nodes++;
	}
	return (nodes);
}
/**
 * print_input_list - prints the contents of a linked list
 * @h: pointer to linked list
 * Return: number of nodes
 */
size_t print_input_list(const list_t *h) /*UNECESSARY FUNCTION*/
{
	size_t nodes = 0;
	const list_t *traverser = h;

	while (traverser != NULL)
	{
		_write(traverser->str);
		traverser = traverser->next;
		nodes++;
	}
	return (nodes);
}
