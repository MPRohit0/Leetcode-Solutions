class Solution {
public:
    void sortColors(vector<int>& nums) {
        int s = 0, e = nums.size()-1;
        int p =0;
        while(p<=e){
            if(nums[p]==0){
                swap(nums[s],nums[p]);
                p++;s++;
            }else if(nums[p]==2){
                swap(nums[e],nums[p]);
                e--;
            }else{
                p++;
            }
        }
    }
};