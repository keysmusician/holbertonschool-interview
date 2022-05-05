#!/usr/bin/python3
"""
Write a recursive function that queries the Reddit API, parses the title of all
hot articles, and prints a sorted count of given keywords.
"""
import collections
import requests


def count_words(subreddit, word_list, after=None, depth=0,
                word_count=collections.Counter()):
    """
    Prints a sorted count of given keywords found in Reddit's hot articles.
    """
    url = 'http://www.reddit.com/r/{}/hot.json'.format(subreddit)
    headers = {'User-Agent': '0x13 Count It!'}
    parameters = {'after': after, 'limit': 100, 'show': 'all'}
    response = requests.get(url, headers=headers, params=parameters)
    if not response.ok:
        return
    response = response.json()

    after = response['data']['after']
    for child in response['data']['children']:
        title = child['data']['title'].lower().split()
        for word in title:
            for search_word in word_list:
                if word == search_word.lower():
                    word_count[word] += 1
    if after:
        count_words(subreddit, word_list, after, depth + 1, word_count)

    if depth == 0:
        sorted_count = sorted(word_count.items(), key=lambda x:(-x[1], x[0]))
        for key, value in sorted_count:
            print(f'{key}: {value}')
