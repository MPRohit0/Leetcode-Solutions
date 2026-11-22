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
    void dfs(TreeNode*root, int &prev, int& ans){
        if(!root) return;

        if(root -> left) dfs(root -> left, prev, ans);
        
        
        if(prev != -1) ans = min(ans, abs(prev - root -> val));
        prev = root -> val;

        if(root -> right) dfs(root -> right, prev, ans);
    }

    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        int prev = -1;

        dfs(root, prev, ans);

        return ans;
    }
};