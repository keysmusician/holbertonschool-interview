#include <stdio.h>
#include <math.h>

/**
 * menger - print a menger sponge
 *
 * @level: number of levels to print
 */
void menger(int level)
{
	int y, x, side_length, segment, depth, n;
	char c;

	side_length = (int)pow(3, level);

	for (y = 0; y < side_length; y++)
	{
		for (x = 0; x < side_length; x++)
		{
			c = '#';
			segment = side_length;
			depth = level;
			while (depth-- > 0)
			{
				segment /= 3;
				n = y / segment % 3 * 3 + x / segment % 3;
				if (n == 4)
				{
					c = ' ';
					break;
				}
			}
			putchar(c);
		}
		printf("\n");
	}
}
