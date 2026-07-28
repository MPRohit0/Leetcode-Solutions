class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int w = 1, r = 1;
        while(r<nums.size()){
            if(nums[r]!=nums[w-1]){
                swap(nums[r],nums[w]);
                w++;
            }
            r++;
        }
        return w;
    }
};