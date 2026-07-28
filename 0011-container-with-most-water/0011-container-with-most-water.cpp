class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int lp =0,rp = height.size()-1;
        while (rp>lp){
            int area = min(height[lp],height[rp])*(rp-lp);
            max_area = max(max_area,area);
            if(height[lp]>height[rp]){
                rp--;
            }else{
                lp++;
            }
        }
        return max_area;
    }
};