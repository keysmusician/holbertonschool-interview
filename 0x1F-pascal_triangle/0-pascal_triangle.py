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
    return [list(str(11 ** m)) for m in range(n)]
