#!/usr/bin/python3
from sys import stdin


line_number = 1
total_file_size = 0
code_counts = dict()

while True:
    line = stdin.readline()\
                .replace('"GET /projects/260 HTTP/1.1"', '', 1)\
                .replace('- [', '', 1)\
                .replace(']', '', 1)
    try:
        IP_address, date, time, status_code, file_size = line.split()
        total_file_size += int(file_size)
        if code_counts.get(int(status_code)):
            code_counts[int(status_code)] += 1
        else:
            code_counts[int(status_code)] = 1

    except ValueError:
        pass

    if line_number % 10 == 0:
        print('File size:', total_file_size)
        for code, count in sorted(code_counts.items()):
            print('{}: {}'.format(code, count))

    line_number += 1
