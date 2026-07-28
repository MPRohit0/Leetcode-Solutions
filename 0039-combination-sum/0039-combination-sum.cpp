class Solution {
public:
    void com(int i,int sum,int tar, vector<int>& temp, vector<int>& nums, vector<vector<int>>& ans){
        if(i==nums.size()||sum>tar){
            if(tar==sum){
                ans.push_back(temp);
            }
            return;
        }

        //include same
        sum+=nums[i];
        temp.push_back(nums[i]);
        com(i,sum,tar,temp,nums,ans);
        sum-=nums[i];
        temp.pop_back();

        //exclude this
        com(i+1,sum,tar,temp,nums,ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        com(0,0,target,temp,candidates,ans);
        return ans;
    }
};