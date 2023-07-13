#include <iostream>
#include <functional>
#include <vector>

using namespace std;

int min_one(int x) {
    return x - 1;
}

int min_three(int x) {
    return x - 3;
}

int min_four(int x) {
    return x - 4;
}

struct Change {
  function<int(int)> reverse_op;
  int cost;
};

int min_ops_dp(int input, vector<Change> change_op_tree)
{
  vector<int> min_ops(input, 1); //all vals init to 1
  
  for(int i = 1; i < input; i++)
  {
    int min_cost = i + 1;
    
    for (const auto& change_op : change_op_tree) 
    {
      int res = change_op.reverse_op(i + 1); // i + 1 = denomination
      
      if(res < 0) continue;

      int cost = change_op.cost;
      if(res!=0) cost += min_ops[res - 1];

      if(cost < min_cost) min_cost = cost;
    }

    min_ops[i] = min_cost;
  }

  return min_ops[input - 1];
}

int main() {
  vector<Change> change_tree = {
        {min_one, 1},
        {min_three, 1},
        {min_four, 1}
    };

  

  int input;
  std::cin >> input;

  std::cout << min_ops_dp(input, change_tree)<< '\n'; 
}
