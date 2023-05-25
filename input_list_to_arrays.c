#include "main.h"
/**
  * conv_inputlist_to_array - converts linked list to double ptr array
  * @input_list_head: pointer to input linked list
  * @i: number of nodes
  * Return: the converted input array
  */
char **conv_inputlist_to_array(list_t *input_list_head, size_t i)
{
	char **input_array;
	list_t *tmp;
	size_t j = 0;
	int len = 0;

	tmp = input_list_head;
	input_array = _grand_malloc(sizeof(char *) * (i + 1));
	while (tmp != NULL)
	{
		len = _strlen(tmp->str);
		input_array[j] = _grand_malloc(sizeof(char) * (len + 1));
		_memcopy(input_array[j], tmp->str, len);
		tmp = tmp->next;
		j++;
	}
	input_array[j] = NULL;
	return (input_array);
}
