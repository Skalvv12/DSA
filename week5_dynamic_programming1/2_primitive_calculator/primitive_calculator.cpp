#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

#include <functional>
#include <vector>

using namespace std;

int min_one(int x) {
    return x - 1;
}

int del_two(int x) {
    return x/2;
}

int del_three(int x) {
    return x/3;
}

struct Operation {
  function<int(int)> reverse_op;
  int cost;
  string name;
};

struct Data {
  int min_ops;
  vector<string>& name_ops;
};

const Data min_ops_dp(int input, vector<Operation> calc_op_tree) {
  vector<int> min_ops(input, 1); //all vals init to 1
  vector<string> name_ops(input);

  for(int i = 1; i < input; i++)
  {
    int min_cost = i + 1;
    string min_op_name = "";
    for (const auto& calc_op : calc_op_tree) 
    {
      int res = calc_op.reverse_op(i + 1); // i + 1 = denomination
      
      if(res % 1 != 0) continue;

      int cost = calc_op.cost;
      if(res!=0) cost += min_ops[res - 1];

      if(cost < min_cost)
      {
        min_cost = cost;
        min_op_name = calc_op.name;
      }
    }

    min_ops[i] = min_cost;
    name_ops[i] = min_op_name;
  }

  return { min_ops[input - 1], name_ops };
}

const vector<int>& find_optimal_sequence(int n)
{
  vector<Operation> calcTree = {
    {min_one, 1, "min_one"},
    {del_two, 1, "del_two"},
    {del_three, 1, "del_three"}
  };

  Data data = min_ops_dp(n, calcTree);
  
  vector<int> answer(data.min_ops + 1);
  answer[0] = data.min_ops;
  answer[answer.size() - 1] = 0;
  int last_num = n;

  for(int i = answer.size() - 2; i > 0; i--)
  {
    for(const auto& calc_op: calcTree)
    {
      if(data.name_ops[i] == calc_op.name)
      {
        answer[i] = calc_op.reverse_op(last_num);
      }
    }
  }
  return answer;
}

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  const vector<int>& sequence = find_optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
