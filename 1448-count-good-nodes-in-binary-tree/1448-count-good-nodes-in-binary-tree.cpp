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
    void dfs(TreeNode* root, vector<int>& prev, int& ans){
        if(!root) return;
        
        if(prev.empty() || prev.back() <= root -> val){
            ans++;
            prev.push_back(root -> val);
        }

        if(root -> left) dfs(root -> left, prev, ans);
        if(root -> right) dfs(root -> right, prev, ans);

        if(prev.back() == root->val) prev.pop_back();
    }

    int goodNodes(TreeNode* root) {
        int ans = 0;
        vector<int> temp;

        dfs(root, temp, ans);

        return ans;
    }
};