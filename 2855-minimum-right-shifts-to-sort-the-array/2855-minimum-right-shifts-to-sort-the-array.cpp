class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int n = nums.size();

        int min_i = 0;
        for(int i = 1; i < n; i++){
            if(nums[i] < nums[min_i]){
                min_i = i;
            }
        }

        int temp = n-1;
        int j = min_i;
        while(temp--){
            if(nums[(j)%n] > nums[(j+1)%n]){
                return - 1;
            }
            j++;
        }

        return (min_i == 0)? 0 : n - min_i;
    }
};