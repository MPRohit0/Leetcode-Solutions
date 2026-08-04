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

    TreeNode* lol(TreeNode* root){
        if(!root) return root;
        if(!root-> right && !root->left) return root;

        TreeNode* left = lol(root->left);
        TreeNode* right = lol(root->right);
        
        TreeNode* curr = root;
        curr->left = nullptr;
        curr->right = left;
        while(curr->right){
            curr = curr -> right;
        }
        curr -> right = right;
        return root;

    }

    void flatten(TreeNode* root) {
        lol(root);
    }
};