#!/usr/bin/python3
"""
You have n number of locked boxes in front of you. Each box is numbered
sequentially from 0 to n - 1 and each box may contain keys to the other boxes.
A key with the same number as a box opens that box. The first box is unlocked.

Write a method that determines if all the boxes can be opened.
"""


def canUnlockAll(boxes):
    """
    Determines if all lockboxes can be opened.

    Args:
        boxes: A 2D array representing a series of boxes containing keys to
        other boxes. There can be keys that do not have boxes.

    Returns: True if all boxes can be opened, otherwise returns False
    """
    if not boxes:
        return None

    boxes = {index: key for index, key in enumerate(boxes)}

    keys = set(boxes[0])
    del boxes[0]
    while keys:
        new_keys = []
        for key in keys:
            try:
                new_keys += boxes[key]
                del boxes[key]
            except KeyError:
                continue
        keys = set(new_keys)

    return False if boxes else True
