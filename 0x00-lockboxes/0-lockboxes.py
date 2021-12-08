#!/usr/bin/python3
# Lock Boxes Interview Algorithm


def canUnlockAll(boxes):
    """ lockboxes solver """
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
