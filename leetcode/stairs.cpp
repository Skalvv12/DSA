#include <cmath>

class Solution {
public:
    int climbStairs(int n) {
        if(n == 0) return 0;
        int mod = n % 2;
        int times = (n - mod)/2;
        int ways = pow(2, times) + mod;
        return ways;
    }
};

int main()
{
    Solution solution;

    int res = solution.climbStairs(3);
    return res;
}