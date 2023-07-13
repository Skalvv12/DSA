#include <iostream>
#include <string>
#include <vector>
#include <exception>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



class FoundResult : public std::exception {
public:
    bool result;
    FoundResult(bool val) : result(val) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        bool result = true;
        try{
            int tmp = checkRecursive(root, 0);
        } catch(const FoundResult& fr)
        {
            return fr.result;
        }

        return result;
    }

    int checkRecursive(TreeNode* root, int added_depth)
    {
        if(!root) return added_depth;
        added_depth++;
        int added_depth_left = checkRecursive(root->left, added_depth);
        int added_depth_right = checkRecursive(root->right, added_depth);
        if(abs(added_depth_right - added_depth_left) > 1)
        {
            throw FoundResult(false);
        }
        added_depth = max(added_depth_left, added_depth_right);
        return added_depth;
    }
    
};


int main()
{
    Solution solution;

    TreeNode* node15 = new TreeNode(15);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node20 = new TreeNode(20, node15, node7);
    TreeNode* node9 = new TreeNode(9);
    TreeNode* root = new TreeNode(3, node9, node20);

    bool result = solution.isBalanced(root);
    cout << result << "\n";
}