class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);
        
        int prev = nums[0];
        for(int i = 1; i < nums.size(); i++){
            ans[i] *= prev;
            prev *= nums[i];
        }

        int next = nums[nums.size()-1];
        for(int i = nums.size()-2; i >= 0; i--){
            ans[i] *= next;
            next *= nums[i];
        }

        return ans;
    }
};