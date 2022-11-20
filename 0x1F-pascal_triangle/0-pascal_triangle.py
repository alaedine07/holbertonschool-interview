#!/usr/bin/python3
"""
Pascale triangle
"""


def factorial(n):
    if n == 0:
        return 1
    prod = 1
    for i in range(1, n+1):
        prod = prod * i
    return prod


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
