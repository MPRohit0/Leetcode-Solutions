class Solution {
public:
    int r(vector<int>& nums){
        stack<int> s;
        int n = nums.size();
        int ans = 0;

        for(int i = 0; i <= n; i++){
            int curr_height = (i == n) ? 0 : nums[i];
            while(!s.empty() && nums[s.top()] > curr_height){
                int top = s.top(); s.pop();

                int h = nums[top];
                int r = i;
                int l = s.empty()? -1 : s.top();
                
                ans = max(ans, h*(r - l - 1));
            }

            s.push(i);
        }

        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> nums(n,0);

        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '1') nums[j]++;
                else nums[j] = 0;
            }

            ans = max(ans,r(nums));
        }

        return ans;
    }
};