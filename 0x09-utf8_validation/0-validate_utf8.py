#!/usr/bin/python3
"""
UTF-8 validation module
"""


def validUTF8(data):
    """
    function to check if data is valid utf-8
    https://leetcode.com/problems/utf-8-validation/solution/
    """
    # number of bytes in the current UTF-8 character
    n_bytes = 0

    # for each integer in data array
    for num in data:
        # convert to binary and only get the least significant 8 bits
        bin_rep = format(num, '#010b')[-8:]

        if n_bytes == 0:
            # get the number of 1s in the beggining of the string
            for bit in bin_rep:
                if bit == '0':
                    break
                n_bytes += 1
            if n_bytes == 0:
                continue
            if n_bytes == 1 or n_bytes > 4:
                return False
        else:
            if not (bin_rep[0] == '1' and bin_rep[1] == '0'):
                return False
        n_bytes -= 1
    return n_bytes == 0
