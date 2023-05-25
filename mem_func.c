#include "main.h"
/**
  * _grand_malloc - allocate memory, including checking for NULL
  * @mem_needed: memory needed
  * Return: the allocated memory including null byte
  */
void *_grand_malloc(size_t mem_needed)
{
	unsigned int i;
	char *malloced_head;

	i = 0;
	malloced_head  = malloc(mem_needed);
	if (malloced_head == NULL)
	{
		perror("OUT OF MEMORY!!!! RUN AWAY!!!!!");
		exit(EXIT_FAILURE);
	}
	while (i < mem_needed)
	{
		malloced_head[i] = '\0';
		i++;
	}
	return (malloced_head);
}
/**
 * _memcopy -  a function that copies memory area
 * @src: pointer to be copied
 * @dest: pointer to copy the source to
 * @n: the number of bytes to be copied
 * Return: a pointer to dest
 */
char *_memcopy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
/**
 * _memset - a function that fills memory with a constant byte
 * @s: pointer to the string
 * @b: constant byte
 * @n: the number of bytes to be filled with b
 * Return: a pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}
	return (s);
}
