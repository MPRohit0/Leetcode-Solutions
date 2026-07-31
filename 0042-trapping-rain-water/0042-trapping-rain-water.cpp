class Solution {
public:
    int trap(vector<int>& height) {
        //min(max l, max r) - curr -> curr_water

        int l = 0, r = height.size() - 1;
        int curr_max = INT_MIN;

        int ans = 0;
        while(l <= r){
            if(height[l] <= curr_max){
                ans += curr_max - height[l++];
            }else if(height[r] <= curr_max){
                ans += curr_max - height[r--];
            }else{
                if(height[l] < height[r]){
                    curr_max = height[l++];
                }else{
                    curr_max = height[r--];
                }
            }
        }

        return ans;
    }
};