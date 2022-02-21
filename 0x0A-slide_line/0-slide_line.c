#include "slide_line.h"

/**
 * slide_line - slides and merges an array of integers as in the game 2048
 *
 * @line: a line to slide and merge
 * @size: the length of @line
 * @direction: the direction to slide the values in @line. Must be either
 * SLIDE_LEFT or SLIDE_RIGHT (see "slide_line.h").
 *
 * Return: 1 on success, 0 on failure.
 */
int slide_line(int *line, size_t size, int direction)
{
	size_t i = 0, i_out = 0, end = 0;
	int n = 0, n_prev = 0;
	char inc = 0;

	if (direction == SLIDE_LEFT)
		i = 0, i_out = 0, end = size, inc = 1;
	else if (direction == SLIDE_RIGHT)
		i = size - 1, i_out = size - 1, end = -1, inc = -1;
	else
		return (0);

	for (; i != end; i += inc)
	{
		n = line[i];
		if (n && n_prev)
		{
			if (n == n_prev)
			{
				line[i_out] = n + n_prev; /* Save merged */
				n_prev = 0;
			}
			else /* Save previous */
			{
				line[i_out] = n_prev;
				n_prev = n;
			}
			i_out += inc;
		}
		else if (n) /* Find a non-zero number */
			n_prev = n;
	}
	line[i_out] = n_prev; /* If line ends before compare, save prev */
	i_out += inc;
	while (i_out != end) /* Fill the rest of line with zeros */
	{
		line[i_out] = 0;
		i_out += inc;
	}

	return (1);
}
