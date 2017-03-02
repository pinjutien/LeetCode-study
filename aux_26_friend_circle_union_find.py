import numpy as np
import pandas as pd


# https://www.cs.princeton.edu/~rs/AlgsDS07/01UnionFind.pdf
class Uion_find(object):

    def __init__(self, input_data):
        # input_data: always starting from 0
        self.data = input_data
        self.index_id = list(range(len(self.data)))

    def find(self, p, q):
        return (self.index_id[p] == self.index_id[q])

    def unite(self, p, q):
        pid_temp = self.index_id[p]
        for i in range(len(self.index_id)):
            if(self.index_id[i] == pid_temp):
                self.index_id[i] = self.index_id[q]

    def count_circle(self):
        return len(set(self.index_id))
            




if __name__ == "__main__":

    a = Union_find(list(range(10)))
    a.unite(3,4)
    a.unite(3,4)
    a.count_circle()

    '''
    there are 4 people and we assign each of them id. For example, 0,1,2,3
    Their friendship can be represented by 2x2 matrix.

    friend_matrix[i,j]: 
                 1 if person i and person j are friend.
                 0 if person i and person j are NOT friend.

    Thus, this matrix is a symmetric matrix and the diagonal element is 1.
    '''
    
    friend_matrix = np.array([
        [1,0,1,1],
        [0,1,1,0],
        [1,1,1,0],
        [1,0,0,1]
    ])

    n_people = friend_matrix.shape[0]
    friend_union = Union_find(list(range(n_people)))

    for i in range(n_people):
        for j in range(n_people):
            if friend_matrix[[i, j]] == 1:
                friend_union.unite(i,j)
            
    print("number of friend circle: "friend_union.count_circle())
