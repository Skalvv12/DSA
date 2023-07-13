#include <cassert>
#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        uint l_idx = 0;

        uint r_idx = (nums.size() > 0) ? nums.size() - 1 : 0;
        uint mid_idx = 0;

        while(l_idx <= r_idx)
        {
            mid_idx = (l_idx + r_idx) / 2;
            if(nums[mid_idx] < target)
            {
                l_idx = mid_idx + 1;
            }
            else if(target < nums[mid_idx])
            {
                if((int)mid_idx - 1 < 0) break;
                r_idx = mid_idx - 1;
                
            }
            else if(target == nums[mid_idx])
            {
                return mid_idx;
            }
        }
        return -1;
    }


};

int main()
{
    Solution solution;

    vector<int> nums = {5};
    int target = -5;

    cout << solution.search(nums, target) << "\n";

}
