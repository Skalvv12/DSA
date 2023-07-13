#include <iostream>
#include <string>
#include <vector>
using std::string;
using namespace std;

int edit_distance(const string &str1, const string &str2) {
  //write your code here
  const vector<vector<int>> DPtable(str1.length() + 1, vector<int> (str2.length()) + 1);

  for(int i = 0; i<DPtable.size(); i++)
  {
    for(int j = 0; j<DPtable[i].size(); j++)
    {
      
    }
  }

  return 0;
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
