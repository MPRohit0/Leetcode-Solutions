class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int i = 0, j = nums.size() - 1;
        int ans = 0;
        while(j > i){
            int sum = nums[i] + nums[j];

            if(sum > k) j--;
            else if(sum < k) i++;
            else{
                ans++; i++; j--;
            }
        }

        return ans;
    }
};