#include "main.h"
/**
  * add_env_node - addes the env variables to a linked list
  * @head: head to the env linked list
  * @env_var: environmental variables
  * Return: return the environment linked list
  */
env_t *add_env_node(env_t **head, char *env_var)
{
	env_t *new_node, *tmp;
	char *env_variable;

	new_node = _grand_malloc(sizeof(env_t));
	env_variable = _strdup(env_var);
	if (env_variable == NULL)
	{
		free(new_node);
		return (NULL);
	}
	new_node->key = strtok(env_variable, "=");
	new_node->value = strtok(NULL, "\0");
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
/**
  * create_env_list - creates the linked list from environ
  * @vars: takes in necessary variables
  * Return: returns the linked list from environ variables
  */
int create_env_list(all_variables_t *vars)
{
	unsigned int i;

	i = 0;

	while (environ[i] != NULL)
	{
		add_env_node(&vars->env_hd, environ[i]);
		i++;
	}
	return (i);
}
