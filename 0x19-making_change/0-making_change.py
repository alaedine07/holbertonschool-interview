#!/usr/bin/python3
"""
making change module
"""

def makeChange(coins, total):
    """
    make change
    """
    if total <= 0:
        return 0
    if total in coins:
        return 1
    print(coins)
    # print(coins)
    # print(total)
    min_steps = 789456
    for i in range(0, len(coins)):
        number = coins[i]
        s = coins[i]
        steps = 0
        for j in range(i + 1, len(coins)):
            # print("loop: ", coins[i], coins[j])
            # print("debug 1 : ", s, coins[j])
            s = s + coins[j]
            # print("debug 2: ", s, coins[j])
            if s > total:
                break
            steps = steps + 1
            if s == total:
                if steps <= min_steps:
                    min_steps = steps
                break
    print(min_steps)