'''
https://discuss.leetcode.com/topic/12/design-a-data-structure-that-supports-insert-delete-search-and-getrandom-in-constant-time
Design a data structure that supports insert, delete, search
and getRandom in constant time.
'''

import random

class solution(object):

    def __init__(self):
        self.hash_map = {}
        self.data = []

    def add(self, item):
        self.data.append(item)        
        self.hash_map[item] = len(self.data) - 1


    def remove(self, item):
        if self.search(item):
            del self.data[self.hash_map[item]]
            self.hash_map.pop(item, 'not in the data strucutre')

    def search(self, item):
        return (item in self.hash_map)


    def getrandom(self):
        if (len(self.data) > 0):
            random_index = random.randint(0, len(self.data))
            return self.data[random_index]
            



            
            

