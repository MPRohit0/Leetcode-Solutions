class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> prev(n,0);
        vector<int> nxt(n,0);
        int dp = 0;

        //previous smallest element
        stack<int> s;
        for(int i = 0; i < n; i++){
            while(!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }

            prev[i] = s.empty() ? -1 : s.top();

            s.push(i);
        }

        //next smallest element
        while(!s.empty()){
            s.pop();
        }

        for(int i = n-1; i >= 0; i--){
            while(!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }

            nxt[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        //solving
        for(int i = 0; i < n; i++){
            int w = nxt[i] - prev[i] - 1;
            int area = w*heights[i];

            dp = max(dp, area);
        }

        return dp;
    }
};