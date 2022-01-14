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
 * @is_stable: Whether or not the grid is stable after addition
 */
void sum_grids(int grid1[3][3], int grid2[3][3], int *is_stable)
{
	int i = 0, j = 0;

	*is_stable = 1;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
			if (grid1[i][j] >= 4)
				*is_stable = 0;
		}
	}
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
 * sandpiles_sum - computes the sum of two sandpiles
 *
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i = 0, j = 0, is_stable = 0;
	int up_i = 0, up_j = 0, down_i = 0, down_j = 0, left_i = 0, left_j = 0,
		right_i = 0, right_j = 0;

	while (1)
	{
		sum_grids(grid1, grid2, &is_stable);
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
					up_i = i - 1; /* i index */
					up_j = j; /* j index */
					if (up_i >= 0 && up_i < 3)
						grid2[up_i][up_j] += 1;
					down_i = i + 1; /* i index */
					down_j = j; /* j index */
					if (down_i >= 0 && down_i < 3)
						grid2[down_i][down_j] += 1;
					left_i = i; /* i index */
					left_j = j - 1; /* j index */
					if (left_i >= 0 && left_i < 3)
						grid2[left_i][left_j] += 1;
					right_i = i; /* i index */
					right_j = j + 1; /* j index */
					if (right_i >= 0 && right_i < 3)
						grid2[right_i][right_j] += 1;
				}
			}
		}
	}
}
