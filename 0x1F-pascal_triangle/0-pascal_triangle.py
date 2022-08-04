#!/usr/bin/python3
"""
Create a function that returns a list of lists of integers representing
Pascal's triangle.
"""


def pascal_triangle(n):
    """
    Returns a list of lists of integers representing the Pascal's triangle of
    `n`.
    """
    result = []
    previous_row = [1]

    for _ in range(n):
        result.append(previous_row)
        next_row = [
            a + b for a, b in zip([0] + previous_row, previous_row + [0])
        ]
        # Copying `previous_row` twice isn't very space efficient, but it
        # is readable. If performance is an issue, indexing the previous row
        # directly should improve it.
        previous_row = next_row

    return result
