#!/usr/bin/python3
""" module to solve rain """


def rain(walls):
    """
    rain solver script
    """
    if not walls:
        return 0
    sum = 0
    for i in range(len(walls) - 1):
        if walls[i] > 0:
            j = i + 1
            step = 0
            while (walls[j] == 0 and j < len(walls) - 1):
                j += 1
                step += 1
            if j == len(walls) - 1 and walls[j] == 0:
                return sum
            else:
                # print(walls[i], walls[j])
                min_heigh = min(walls[i], walls[j])
                sum += min_heigh * step
                i = j
    return sum
