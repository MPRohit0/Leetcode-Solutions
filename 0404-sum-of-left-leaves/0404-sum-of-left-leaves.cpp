/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void lol(TreeNode* root, bool flag, int &sum){
        if(!root->left && !root->right){
            if(flag) sum+= root->val;
            return;
        }

        if(root->left) lol(root->left, true, sum);
        if(root->right) lol(root->right, false, sum);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        
        bool flag = 0;
        int sum = 0;
        lol(root, flag, sum);

        return sum;
    }
};