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
n_queens2 = []
n_queens3 = []
n_queens4 = []
row = 1
for col in range(N):
    if row >= N:
        row = 0
    n_queens.append((col, row))
    n_queens2.append((row, N - 1 - col))
    n_queens3.append((row, col))
    n_queens4.append((col, N - 1 - row))
    row += 2

# Remove duplicates
results = set()
[
    results.add(tuple(sorted(l)))
    for l in (n_queens, n_queens2, n_queens3, n_queens4)
]

# Print results
for result in results:
    print(str(result).replace('(', '[').replace(')', ']'))
