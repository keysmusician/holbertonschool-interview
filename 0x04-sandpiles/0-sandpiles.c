#include <stdio.h>

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * sum_grids - sums two grids
 *
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 *
 * Return: Whether or not the grid is stable after addition
 */
int sum_grids(int grid1[3][3], int grid2[3][3])
{
	int i = 0, j = 0, is_stable = 1;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
			if (grid1[i][j] >= 4)
				is_stable = 0;
		}
	}
	return (is_stable);
}

/**
 * clear_grid - fills a grid with 0s
 *
 * @grid: grid to fill with zeros
 */
void clear_grid(int grid[3][3])
{
	int i = 0, j = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid[i][j] = 0;
	}
}

/**
 * set_grid2 - sets grid 2
 *
 * @i: grid 1 vertical index
 * @j: grid 1 horizontal index
 * @grid2: grid2
 */
void set_grid2(int i, int j, int grid2[3][3])
{
	int i2 = 0, j2 = 0, n = 0;
	int i_offset[4] = {0, 0, 1, -1};
	int j_offset[4] = {1, -1, 0, 0};

	for (n = 0; n < 4; n++)
	{
		i2 = i + i_offset[n];
		j2 = j + j_offset[n];
		if (i2 >= 0 && j2 >= 0 && i2 < 3 && j2 < 3)
			grid2[i2][j2] += 1;
	}

}

/**
 * sandpiles_sum - computes the sum of two sandpiles
 *
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i = 0, j = 0, is_stable = 0;

	while (1)
	{
		is_stable = sum_grids(grid1, grid2);
		if (is_stable)
			return;
		printf("=\n");
		print_grid(grid1);
		clear_grid(grid2);
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] > 3)
				{
					grid1[i][j] -= 4;
					set_grid2(i, j, grid2);
				}
			}
		}
	}
}
