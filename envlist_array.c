#include "main.h"
/**
  * conv_list_to_array - converts env_var linked list into a double ptr array
  * @env_head: takes in an env_var linked list
  * @n: the amount of nodes
  * Return: the converted double ptr array
  */
char **conv_list_to_array(env_t *env_head, int n)
{
	char **array;
	env_t *tmp;
	int len, i, j;
	char *val;

	len = i = 0;
	tmp = env_head;
	array = _grand_malloc(sizeof(char *) * (n + 1));

	while (tmp != NULL)
	{
		len = _strlen(tmp->key) + _strlen(tmp->value);
		array[i] = _grand_malloc(sizeof(char) * (len + 2));
		if (array[i] == NULL)
		{
			perror("Array is empty");
			free(array);
			return (NULL);
		}
		_memcopy(array[i], tmp->key, _strlen(tmp->key));
		array[i][_strlen(tmp->key)] = '=';
		val = tmp->value;
		for (j = 0; j < _strlen(val); j++)
		{
			array[i][_strlen(tmp->key) + 1 + j] = val[j];
		}
		tmp = tmp->next;
		i++;
	}
	array[i] = NULL;
	return (array);
}
