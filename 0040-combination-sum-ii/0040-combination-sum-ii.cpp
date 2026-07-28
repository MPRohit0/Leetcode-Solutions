class Solution {
public:
    void com(int i,int sum,int tar,vector<int>& temp, vector<int>& nums, vector<vector<int>>& ans){
        if(i==nums.size()||sum>tar){
            if(tar==sum) ans.push_back(temp);
            return;
        }

        //inclusion
        temp.push_back(nums[i]);
        com(i+1,sum+nums[i],tar,temp,nums,ans);
        temp.pop_back();

        //exclusion
        int idx = i+1;
        while(idx<nums.size()&&nums[idx]==nums[idx-1]) idx++;
        com(idx,sum,tar,temp,nums,ans);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        vector<vector<int>> ans;

        com(0,0,target,temp,candidates,ans);
        return ans;
    }
};