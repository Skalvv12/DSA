#include <iostream>

using namespace std;


int answer = 4;

bool isBadVersion(int version)
{
    if(version < answer)
    {
        return false;
    }
    return true;
}

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long idx = 0;

        long long l = 0;
        long long r = n;
        if(isBadVersion(1))
        {
            return 1;
        }

        while(l < r)
        {
            idx  = l + (r-l)/2;
            if(isBadVersion(idx))
            {
                r = idx;
            }
            else
            {
                l = idx + 1;
            }
        }    
        
        return (int)r;
    }

    
};




int main()
{
    Solution solution;

    cout << solution.firstBadVersion(5) << "\n";

    return 0;
}