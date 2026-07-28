class Solution {
public:
    int jump(vector<int>& nums) {
        int j = 0;
        int f = 0, curr_end = 0;

        for(int i=0;i<nums.size()-1;i++){
            f = max(f,i+nums[i]);
            if(curr_end == i){
                j++;
                curr_end = f;
            }
        }

        return j;
    }
};