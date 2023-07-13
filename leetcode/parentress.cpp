
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    bool isValid(const string s) {
        std::vector<char> stack;
        for(char c: s)
        {
            switch(c)
            {
                case '(':
                case '{':
                case '[':
                    stack.push_back(c);
                    break;
                case ')':
                    if (stack.empty() || stack.back() != '(') return false;
                    stack.pop_back();
                    break;
                case '}':
                    if (stack.empty() || stack.back() != '{') return false;
                    stack.pop_back();
                    break;
                case ']':
                    if (stack.empty() || stack.back() != '[') return false;
                    stack.pop_back();
                    break;
                default:
                    break;
            }
        }
        return true;
    }
};


int main()
{
    Solution solution;

    string str = "[{[(())]}{{{(([])){{[[]]}}}}}]";
    bool result = solution.isValid(str);
    cout << result << "\n";

}