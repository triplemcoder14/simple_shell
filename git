#include "shell.h"
/**
  * get_builtin_func - function to get the builtin function
  * @cmd: pointer to the command
  * Return: 0
  */
int (*get_builtin_func(char *cmd))()
{
	int i;
	builtin format[] = {
		{"env", print_env},
		{"setenv", _setenv},
		{NULL, NULL}
	};
	for (i = 0; format[i].cmd; i++)
	{
		if (_strncmp(cmd, format[i].cmd, _strlen(format[i].cmd)) == 0)
			return (format[i].func);
	}
	return (0);
}
