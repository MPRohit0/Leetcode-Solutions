class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int ans = nums[0]+nums[1]+nums[2];
        for(int i = 0; i<n; i++){
            int s = i+1; 
            int e = n-1;
            while(e > s){
                int curr_sum = nums[i]+nums[s]+nums[e];
                if(abs(target - ans) > abs(target - curr_sum)){
                    ans = curr_sum;
                }

                if(curr_sum == target) return target;
                if(curr_sum > target) e--;
                else s++; 
            }
        }

        return ans;
    }
};