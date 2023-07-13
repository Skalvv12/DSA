import numpy as np

def binary_search(keys, query):
    mid_num = len(keys)//2
    mid_key = keys[mid_num]
    res = False
    
    if(len(keys) == 1 and mid_key != query):
        return False
    
    if(mid_key < query):
        res = binary_search(keys[mid_num:len(keys)], query)
    elif(mid_key > query):
        res = binary_search(keys[0:mid_num], query)
    elif(mid_key == query):
        return True
    
    return res

def binary_search_q(keys, query):
    res = [-1 for i in range(len(query))]
    for i in range(len(query)):
        res[i] = i if binary_search(keys, query[i]) else -1
    return res
        

if __name__ == '__main__':
    num_keys = int(input())
    input_keys = list(map(int, input().split()))
    assert len(input_keys) == num_keys

    num_queries = int(input())
    input_queries = list(map(int, input().split()))
    assert len(input_queries) == num_queries

    
    print(binary_search_q(input_keys, input_queries), end=' ')
