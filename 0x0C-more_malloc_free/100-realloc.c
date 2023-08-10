#include <stdlib.h>
#include "main.h"

/**
 * *_realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the memory previsouly allocated by malloc
 * @old_size: size of the allocated memory for ptr
 * @new_size: new size of the new memory block
 *
 * Return: pointer to the newly allocated memory block
 */
void *_realloc(void *r, unsigned int old_size, unsigned int new_size)
{
	char *r1;
	char *old_r;
	unsigned int i;

	if (new_size == old_size)
		return (r);

	if (new_size == 0 && r)
	{
		free(r);
		return (NULL);
	}

	if (!r)
		return (malloc(new_size));

	r1 = malloc(new_size);
	if (!r1)
		return (NULL);

	old_r = r;

	if (new_size < old_size)
	{
		for (i = 0; i < new_size; i++)
			r1[i] = old_r[i];
	}

	if (new_size > old_size)
	{
		for (i = 0; i < old_size; i++)
			r1[i] = old_r[i];
	}

	free(r);
	return (r1);
}

