#!/usr/bin/python3
""" Module for parsing logs """
import sys
import re


def check_format(line):
    """ check if the line format is valid """
    if "GET /projects/260 HTTP/1.1" in line:
        return 1
    else:
        return 0


def print_stats():
    """ print occurence of each source code """
    codes = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
    total_sizes = 0
    nb_lines = 0
    try:
        for line in sys.stdin:
            if check_format(line):
                nb_lines += 1
                replaced_l = line.replace("-", " ")
                splited_line = replaced_l.split(" ")
                size = splited_line[-1]
                size = size.rstrip("\n")
                x = size.isnumeric()
                if x is False:
                    pass
                status_code = splited_line[-2]
                total_sizes += int(size)
                if status_code.isdigit():
                    if int(status_code) in codes.keys():
                        codes[int(status_code)] += 1
                        if nb_lines == 10:
                            print("File size: {:d}".format(total_sizes))
                            for key, value in codes.items():
                                if value != 0:
                                    print("{:}: {:}".format(key, value))
                            nb_lines = 0
    except Exception:
        pass
    finally:
        print("File size: {:d}".format(total_sizes))
        for key, value in codes.items():
            if value != 0:
                print("{:}: {:}".format(key, value))


if __name__ == '__main__':
    print_stats()
