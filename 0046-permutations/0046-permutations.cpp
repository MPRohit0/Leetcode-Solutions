class Solution {
public:
    void bt(vector<int>& nums, unordered_set<int> t,vector<vector<int>>& ans,vector<int>& temp, int n, int i){
        if(i == n){
            ans.push_back(temp);
            return;
        }

        for(int j: nums){
            if(t.count(j)) continue;

            t.insert(j);
            temp.push_back(j);
            bt(nums, t, ans, temp, n, i+1);
            temp.pop_back();
            t.erase(j);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set <int> t;

        vector<vector<int>> ans;
        vector<int> temp;

        bt(nums, t, ans,temp,nums.size(),0);

        return ans;
    }
};