#!/usr/bin/python3
"""
    Method that determines if all the boxes can be opened.
"""


def canUnlockAll(boxes):
    """
        Return True if ALL boxes can be opened, else return False.
    """
    l = len(boxes)
    d = {}
    d[0] = "unlocked"
    for index in range(1, l):
        d[index] = "locked"
    keys = []
    for key in boxes[0]:
        keys.append(key)
    for index in range(1, l):
        if index in keys:
            for e in boxes[index]:
                if e not in keys and e != 0 and e is not None:
                    keys.append(e)
            d[index] = "unlocked"
    key = 0
    while (key < len(d) - 1):
        if d[key] == "locked":
            if key in keys:
                for e in boxes[key]:
                    if e not in keys and e != 0 and e is not None:
                        keys.append(e)
                d[key] = "unlocked"
                key = 0
        key += 1
    if ("locked" in d.values()):
        return False
    else:
        return True
