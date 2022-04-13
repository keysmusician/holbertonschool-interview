#!/usr/bin/python3
"""
Given a list of non-negative integers representing the heights of walls with
unit width 1, as if viewing the cross-section of a relief map, calculate the
maximum square units of water retained after it rains.
"""


def rain(walls):
    """
    Solves the "rain" prompt.

    walls: A list of non-negative integers.

    Return: An integer indicating total square units of rainwater retained.
    """
    grid = []
    max = 0
    for n in walls:
        grid.append([1] * n)
        max = n if n > max else max

    total = 0
    for i in range(max):
        start = False
        length = 0
        for j in range(len(walls)):
            try:
                if grid[j][i]:
                    if start:
                        total += length
                        length = 0
                    start = True
            except IndexError:
                if start:
                    length += 1
    return total
