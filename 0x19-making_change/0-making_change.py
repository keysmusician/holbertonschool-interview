#!/usr/bin/python3
"""
Given a pile of coins of different values, determine the fewest number of coins
needed to meet a given amount total.
"""


def makeChange(coins, total):
    """ Solves the making change problem. """
    if type(total) is not int:
        return -1
    if total <= 0:
        return 0
