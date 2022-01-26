#!/usr/bin/python3
from collections import Counter
import signal
from sys import stdin


line_number = 1
total_file_size = 0
# codes = [200, 301, 400, 401, 403, 404, 405, 500]
code_counts = Counter()


def handle_sigint(signal, frame):
    print('File size:', total_file_size)
    for code, count in sorted(code_counts.items()):
        print('{}: {}'.format(code, count))
    exit()

signal.signal(signal.SIGINT, handle_sigint)

while True:
    line = stdin.readline()\
                .replace('"GET /projects/260 HTTP/1.1"', '', 1)\
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

