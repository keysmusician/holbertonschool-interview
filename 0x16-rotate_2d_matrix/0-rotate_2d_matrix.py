#!/usr/bin/python3
""" Given an n x n 2D matrix, rotate it 90 degrees clockwise. """


def rotate_2d_matrix(matrix):
    """ Rotates a 2D square matrix 90 degrees clockwise. """
    result = [list(row) for row in matrix]
    length = len(matrix)

    for i in range(length ** 2):
        row, col = i // length, i % length
        row2, col2 = col, (length - 1 - row)
        matrix[row2][col2] = result[row][col]
