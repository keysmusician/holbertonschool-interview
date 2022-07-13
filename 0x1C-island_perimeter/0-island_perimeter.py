#!/usr/bin/python3
"""
Create a function that returns the perimeter of the island described in grid:

- `grid` is a list of list of integers:
  - 0 represents water
  - 1 represents land
  - Each cell is square, with a side length of 1
  - Cells are connected horizontally/vertically (not diagonally)
  - The grid is rectangular, with its width and height not exceeding 100
- The grid is completely surrounded by water
- There is only one island (or nothing)
- The island doesn't have "lakes" (water inside that isn't connected to the
  water surrounding the island)
"""


def island_perimeter(grid):
    """ Returns the perimeter of the island described in `grid`. """
    perimeter = 0

    height, width = len(grid), len(grid[0])

    for grid_index in range(width * height):
        X, Y = grid_index % width, grid_index // width

        if grid[Y][X] == 1:
            directions = [
                (X, Y - 1),  # up
                (X, Y + 1),  # down
                (X - 1, Y),  # left
                (X + 1, Y),  # right
            ]

            for x, y in directions:
                # Ensure indexes are valid
                if (x >= 0 and x < width and
                        y >= 0 and y < height and grid[y][x]):
                    continue
                else:  # If there's no adjacent land cell,
                    # or the index falls beyond the border, increment
                    perimeter += 1

    return perimeter
