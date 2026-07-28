class Solution {
public:
    void sub(int start, vector<int>& nums, 
               vector<int>& temp, 
               vector<vector<int>>& ans) {

    ans.push_back(temp);

    for(int i = start; i < nums.size(); i++) {

        if(i > start && nums[i] == nums[i-1])
            continue;

        temp.push_back(nums[i]);
        sub(i+1, nums, temp, ans);
        temp.pop_back();
    }
               }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        sub(0,nums,temp,ans);
        return ans;
    }
};