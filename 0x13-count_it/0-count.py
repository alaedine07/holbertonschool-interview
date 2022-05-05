#!/usr/bin/python3
""" Count it module """
import requests


def count_words(subreddit, word_list, after="", word_counter=None):
    """
    Count word appearance in subreddit
    """
    # initiate the counter dictionary
    if word_counter is None:
        word_counter = {item: 0 for item in word_list}

    # if last page
    if after is None:
        words = word_counter.items()
        sorted_words = sorted(word, key=lambda x: x[1])[::-1]
        for (key, value) in sorted_words:
            if value != 0:
                print("{}: {}".format(key, value))
        return None

    # at first the after param will be empty then supplied from data
    params = {'after': after, 'limit': 100}
    # the api url
    url = "https://www.reddit.com/r/{}/hot/.json".format(subreddit)
    res = requests.get(url=url, params=params, allow_redirects=False)

    if res.status_code == 200:
        # extract the json response of the data
        data = res.json()
        # extract the after keyword for next page in recursive call
        after = data["data"]["after"]
        # extract childrens
        childrens = [child for child in data["data"]["children"]]
        for child in childrens:
            title = child["data"]["title"]
            words = [words.lower() for words in title.split()]
            for word in word_list:
                word_counter[word] += words.count(word)

        count_words(subreddit, word_list, after, word_counter)
    else:
        # print(res.status_code)
        return None
