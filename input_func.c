#include "main.h"
/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: pointer to a new list head
 * @str: string to be added to linked list
 * Return: the address of the new node, or NULL on failure
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node, *tmp;

	if (str == NULL)
		return (NULL);
	new_node = _grand_malloc(sizeof(list_t));
	new_node->str = _strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}
	new_node->len = _strlen(str);
	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		return (*head);
	}
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new_node;
	return (new_node);
}
