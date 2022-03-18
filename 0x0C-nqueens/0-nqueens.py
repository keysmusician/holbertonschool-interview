#!/usr/bin/python3
"""Solves the N Queens problem."""
from sys import argv


# Input validation:
if len(argv) != 2:
    print("Usage: nqueens N")
    exit(1)

try:
    N = int(argv[1])
    if N < 4:
        print("N must be at least 4")
        exit(1)
except ValueError:
    print("N must be a number")
    exit(1)

# Algorithm: generate all permutations of columns containing a single queen,
# and filter out solutions which contain conflicts along diagonals
n_queens = [n for n in range(N)]


def permutations(elements):
    if len(elements) <= 1:
        yield elements
    else:
        for permutation in permutations(elements[1:]):
            for i in range(len(elements)):
                yield permutation[:i] + elements[0:1] + permutation[i:]


for permutation in permutations(n_queens):
    solution = True
    forward_diagonals = []
    backward_diagonals = []
    for row, column in enumerate(permutation):
        fd = row + column
        bd = N - 1 - (row - column)
        if fd in forward_diagonals or bd in backward_diagonals:
            solution = False
            break
        forward_diagonals.append(fd)
        backward_diagonals.append(bd)

    if solution:
        print([[i, n] for i, n in enumerate(permutation)])
