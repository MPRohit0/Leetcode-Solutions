class Solution {
public:
    bool canJump(vector<int>& nums) {
        int ans = 0; 
        int f = 0;
        int curr_end = 0;
        for(int i=0;i<nums.size();i++){
            f = max(f,nums[i]+i);

            if(curr_end == i){
                curr_end = f;
                ans++;
            }
        }

        return curr_end >= nums.size()-1;
    }
};