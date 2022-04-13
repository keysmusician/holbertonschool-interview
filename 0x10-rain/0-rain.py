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
    total = 0
    for i, wall in enumerate(walls):
        pool_left = 0
        pool_right = 0
        pool_length = 0
        if wall != 0:
            pool_left = wall
            for j, wall in enumerate(walls[i + 1:]):
                if wall != 0:
                    pool_right = wall
                    pool_length = j
                    break
            pool_height = min(pool_left, pool_right)
            total += pool_height * pool_length

    return total
