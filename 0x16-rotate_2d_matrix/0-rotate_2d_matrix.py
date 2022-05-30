#!/usr/bin/python3
"""
rotate 2D matrix module
"""


def rotate_2d_matrix(matrix):
    """
    matrix: 2D matrix of type List
    """
    number_row = len(matrix)
    rotated_matrix = []
    row_len = len(matrix[0])
    index = 0
    while index <= row_len - 1:
        l = []
        for row in matrix:
            l.append(row[index])
        rotated_matrix.append(l)
        index += 1
    for index in range(number_row):
        matrix[index] = rotated_matrix[index]
        matrix[index].reverse()
