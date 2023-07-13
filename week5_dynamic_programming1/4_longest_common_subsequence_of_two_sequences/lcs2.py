import numpy as np

def edit_distance(first_string, second_string):
    dp_table = np.zeros((len(first_string)+1, len(second_string) + 1))
    op_history_table = np.zeros((len(first_string)+1, len(second_string) + 1))
    
    for i in range(dp_table.shape[0]):
        for j in range(dp_table.shape[1]):
            if i == 0 and j == 0:
                dp_table[i, j] = 0
            elif i == 0:
                dp_table[i, j] = dp_table[i, j-1] + 1
            elif j == 0:
                dp_table[i, j] = dp_table[i-1, j] + 1
            else:
                min_ops_num = max(i,j)
                
                current_ops_num = min_ops_num
                #_up
                current_ops_num = dp_table[i-1, j] + 1
                if(current_ops_num <= min_ops_num): 
                    min_ops_num = current_ops_num
                    op_history_table[i, j] = 1
                #_down
                current_ops_num = dp_table[i, j-1] + 1
                if(current_ops_num <= min_ops_num): 
                    min_ops_num = current_ops_num
                    op_history_table[i, j] = 2
                
                if(first_string[i-1] == second_string[j-1]):
                    current_ops_num = dp_table[i-1, j-1]
                    if(current_ops_num <= min_ops_num): 
                        min_ops_num = current_ops_num
                        op_history_table[i, j] = 3
                
                dp_table[i, j] = min_ops_num
                #if first_string[i] == second_string[j]:
    return dp_table[dp_table.shape[0] - 1, dp_table.shape[1] - 1]


if __name__ == '__main__':
    n = int(input())
    a = list(map(int, input().split()))
    assert len(a) == n

    m = int(input())
    b = list(map(int, input().split()))
    assert len(b) == m

    print(edit_distance(a, b))
