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
    total_rain = 0
    if walls:
        for i in range(max(walls) * len(walls)):
            x, y = i % len(walls), i // len(walls)
            if x == 0:
                collect_water, rain = False, 0
            if walls[x] > y:
                if collect_water:
                    total_rain += rain
                    rain = 0
                collect_water = True
            elif collect_water:
                    rain += 1
    return total_rain
