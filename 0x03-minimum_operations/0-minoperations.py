#!/usr/bin/python3
"""Minimum operations module"""


def minOperations(n):
    """ calculate minimum operations """
    operations = 2
    old_chars = 1
    n_chars = 2
    if type(n) is not int or n < 2:
        return 0
    while (n_chars != n):
        if (n % n_chars == 0):
            operations += 2
            old_chars = n_chars
            n_chars *= 2
        else:
            operations += 1
            n_chars += old_chars

    return operations
