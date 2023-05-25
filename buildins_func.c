#include "main.h"
/**
 * _setenv - sets new environmental variable
 * @vars: pointer to a sturct that holds all the needed variables
 * Return: 0 on success, -1 on failure
 **/
int _setenv(all_variables_t *vars)
{
	int i = 0;
	env_t *traverser = vars->env_hd;
	char *key = _strdup(vars->in_ar[1]);
	char *value = _strdup(vars->in_ar[2]);
	char *keynval = _grand_malloc(_strlen(key) + _strlen(value) + 2);

	keynval = _memcopy(keynval, key, _strlen(key));
	keynval = _strncat_env(keynval, "=", 1);
	keynval = _strncat_env(keynval, value, _strlen(value));

	while (traverser != NULL)
	{
		if (_strncmp(key, traverser->key, _strlen(key)) == 0)
		{
			traverser->value = vars->in_ar[2];
			free_env_array(vars->env_ar);
			vars->env_ar = conv_list_to_array(vars->env_hd, vars->n_env_nod);
			i = 1;
			break;
		}
		traverser = traverser->next;
	}
	if (i == 0)
	{
		add_env_node(&vars->env_hd, keynval);
		free_env_array(vars->env_ar);
		vars->env_ar = conv_list_to_array(vars->env_hd, vars->n_env_nod + 1);
		vars->n_env_nod = vars->n_env_nod + 1;
	}
	free(key);
	free(value);
	free(keynval);
	return (0);
}
/**
 * print_env - prints the environment
 * @vars: pointer to a sturct that holds all the needed variables
 * Return: 0 on success
 **/
int print_env(all_variables_t *vars)
{
	unsigned int i;

	i = 0;
	while (vars->env_ar[i] != NULL)
	{
		_write(vars->env_ar[i]);
		_write("\n");
		i++;
	}
	return (0);
}
