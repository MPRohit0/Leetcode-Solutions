class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int ans = 0;
        int n = heights.size();

        for(int i = 0; i <= n; i++){
            int curr_height = (i == n)? 0 : heights[i];
            while(!s.empty() && heights[s.top()] > curr_height){
                int top = s.top(); s.pop();
                int h = heights[top];
                int l = s.empty()? -1 : s.top();
                int r = i;

                ans = max(ans, h * (r-l-1));
            }

            s.push(i);
        }

        return ans;
    }
};