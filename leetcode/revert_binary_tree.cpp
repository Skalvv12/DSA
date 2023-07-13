#include <cassert>
#include <iostream>

using namespace std;


struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
  
class Solution {

public:

    TreeNode* invertTree(TreeNode* root) {
        invertTree_recusion(root);
        return root;
    }

    void invertTree_recusion(TreeNode* root)
    {
        switchNodes(&root->left, &root->right);
        if(root->left) invertTree_recusion(root->left);
        if(root->right) invertTree_recusion(root->right);
    }

private:
    void switchNodes(TreeNode** left, TreeNode** right)
    {
            TreeNode *tmp = *left;
            *left = *right;
            *right = tmp;
            return;
    }
};




int main() {
    // Construct a binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

  
    // TreeNode *tmp = root->left;
    // root->left = root->right;
    // root->right = tmp;
    // Invert the tree

    Solution solution;
    TreeNode *invertedRoot = solution.invertTree(root);

    // Check the result
    assert(invertedRoot->val == 1);
    assert(invertedRoot->left->val == 3);
    assert(invertedRoot->right->val == 2);
    assert(invertedRoot->right->left->val == 5);
    assert(invertedRoot->right->right->val == 4);

    cout << "All tests passed!\n";

    return 0;
}
