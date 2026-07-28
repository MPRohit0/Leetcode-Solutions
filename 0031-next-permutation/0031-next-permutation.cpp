class Solution {
public:
    
    void flip(int s, int e, vector<int>& nums){
        while(e>s){
            swap(nums[s++],nums[e--]);
        }
    }
    
    void nextPermutation(vector<int>& nums) {
        if(nums.size()<=1) return;
        
        int p = nums.size()-2, e = nums.size()-1;

        while(p>=0&&nums[p+1]<=nums[p]){
            p--;
        }
        if(p<0){
            flip(0,e,nums);
            return;
        }

        while(nums[p]>=nums[e]){
            e--;
        }

        swap(nums[p],nums[e]);
        flip(p+1,nums.size()-1,nums);
        return;
    }
};