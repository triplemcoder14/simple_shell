#include "main.h"
/**
 * path_folder_counter - counts how many folders are in the path
 * @paths: takes in the path
 * Return: the number of folders in a path
 */
unsigned int path_folder_counter(char *paths)
{
	unsigned int i, path_folders;

	i = path_folders = 0;

	while (paths[i] != '\0')
	{
		if (paths[i] == ':')
			path_folders++;
		i++;
	}
	return (++path_folders);
}
/**
  * path_parserator - converts env linked list to double ptr, parses by dirs
  * @env_head: takes in the environmental variable linked list
  * Return: returns a double ptr array of environmental variables
  */
char **path_parserator(env_t *env_head)
{
	char **array;
	unsigned int j, i, num_of_path_folders;
	env_t *temp;
	char *paths, *paths_cp;
	char *delim = ":";
	char *p = "PATH";

	temp = env_head;
	if (!temp)
		perror("Error: environment list head is NULL");
	for (i = 0; temp != NULL; i++)
	{
		if (_strcmp(temp->key, p) == 0)
		{
			paths = temp->value;
			num_of_path_folders = path_folder_counter(paths);
			array = _grand_malloc(sizeof(char *) * (num_of_path_folders + 1));
			paths_cp = _strdup(paths);
			if (paths_cp == NULL)
			{
				free(array);
				return (NULL);
			}
			array[0] = strtok(paths_cp, delim);
			for (j = 1; j < num_of_path_folders; j++)
			{
				array[j] = strtok(NULL, delim);
			}
		}
		temp = temp->next;
	}
	return (array);
}
