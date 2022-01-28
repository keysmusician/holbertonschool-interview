#!/usr/bin/python3
"""Reads stdin line by line and computes metrics."""
from collections import Counter
from sys import stdin


line_number = 1
total_file_size = 0
code_counts = Counter()

try:
    for line in stdin:
        if len(line) == 1:
            break

        line = line.replace('"GET /projects/260 HTTP/1.1"', '', 1)\
                    .replace('- [', '', 1)\
                    .replace(']', '', 1)
        try:
            IP_address, date, time, status_code, file_size = line.split()
            total_file_size += int(file_size)
            code_counts[int(status_code)] += 1
        except ValueError:
            pass

        if line_number % 10 == 0:
            print('File size:', total_file_size)
            for code, count in sorted(code_counts.items()):
                print('{}: {}'.format(code, count))

        line_number += 1
except KeyboardInterrupt:
    print('File size:', total_file_size)
    for code, count in sorted(code_counts.items()):
        print('{}: {}'.format(code, count))
