#!/usr/bin/python3
from math import factorial
"""
Pascale triangle
"""


def pascal_triangle(n):
    """
    pascal triangle
    """
    if n <= 0:
        return []
    big_l = []
    for i in range(n):
        small_l = []
        for j in range(i + 1):
            small_l.append(factorial(i)//(factorial(j) * factorial(i - j)))
        big_l.append(small_l)
    return big_l
