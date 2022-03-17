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

# Algorithm:
n_queens = []
row = 1
for col in range(N):
    if row >= N:
        row = 0
    n_queens.append([col, row])
    row += 2

for n in range(2):
    print(n_queens)
    n_queens2 = []
    for coordinate in n_queens:
        coordinate[1] = N - 1 - coordinate[1]
        n_queens2.append(coordinate)
    n_queens = n_queens2
