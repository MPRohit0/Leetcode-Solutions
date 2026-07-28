class Solution {
public:
    void sub(int start,vector<int>& nums,vector<int>& temp,vector<vector<int>>& ans){
        ans.push_back(temp);

        for(int i=start;i<nums.size();i++){
            temp.push_back(nums[i]);
            sub(i+1,nums,temp,ans);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sub(0,nums,temp,ans);
        return ans;
    }
};