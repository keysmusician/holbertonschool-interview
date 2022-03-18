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


class GridSquare:
    board_size = N

    def __init__(self, row, column):
        if row < 0 or column < 0:
            raise ValueError
        self.row = row
        self.column = column

    def __repr__(self):
        return str([self.row, self.column])

    def index(self):
        return self.row * self.board_size + self.column

    def diagonal_forward(self):
        return self.row + self.column

    def diagonal_backward(self):
        return self.board_size - 1 - (self.row - self.column)


# Algorithm:
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
    permutation = [GridSquare(i, n) for i, n in enumerate(permutation)]

    forward_diagonals = []
    backward_diagonals = []
    for square in permutation:
        fd = square.diagonal_forward()
        bd = square.diagonal_backward()
        if fd in forward_diagonals or bd in backward_diagonals:
            solution = False
            break
        forward_diagonals.append(fd)
        backward_diagonals.append(bd)

    if solution:
        print(permutation)
