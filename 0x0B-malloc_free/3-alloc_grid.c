#include "main.h"
#include <stdlib.h>
/**
 * alloc_grid - nested loop to make grid
 * @width: width input
 * @height: height input
 * Return: pointer to 2 dim. array
 */
int **alloc_grid(int width, int height)
{
	int **mi;
	int x, y;

	if (width <= 0 || height <= 0)
		return (NULL);

	mi = malloc(sizeof(int *) * height);

	if (mi == NULL)
		return (NULL);

	for (x = 0; x < height; x++)
	{
		mi[x] = malloc(sizeof(int) * width);

		if (mi[x] == NULL)
		{
			for (; x >= 0; x--)
				free(mi[x]);

			free(mi);
			return (NULL);
		}
	}

	for (x = 0; x < height; x++)
	{
		for (y = 0; y < width; y++)
			mi[x][y] = 0;
	}

	return (mi);
}

