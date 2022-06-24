#!/usr/bin/python3
"""
Given a pile of coins of different values, determine the fewest number of coins
needed to meet a given amount total.
"""


def makeChange(coins, total):
    """ Solves the making change problem. """
    FAIL = -1
    if type(total) is not int:
        return FAIL
    elif total <= 0:
        return 0

    coins = sorted(coins, reverse=True)

    def make_change(coin_index):
        """ Recursion for making change. """
        nonlocal total

        if coin_index >= len(coins):
            return FAIL

        coin = coins[coin_index]

        coin_count = total // coin

        total -= coin * coin_count

        if total == 0:
            return coin_count

        while coin_count >= 0:
            result = make_change(coin_index + 1)
            if result != FAIL:
                return coin_count + result

            coin_count -= 1

            if coin_count >= 0:
                total += coin

        return FAIL

    return make_change(0)
