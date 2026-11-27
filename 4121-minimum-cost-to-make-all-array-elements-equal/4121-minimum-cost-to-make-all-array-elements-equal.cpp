class Solution {
public:
    long long minCost(vector<int>& nums) {
        long long n = nums.size();
        long long ans = LLONG_MAX;
        for(int i = 0; i < n; i++){
            long long curr = i;
            while(curr < n && nums[curr] == nums[i]){
                curr++;
            }
            curr--;

            if(i == curr & (i == 0 || i == n-1)) continue;

            long long cost = 0;
            if(i > 0){cost += nums[i]*(long long)i;}
            if(curr < n - 1){cost += nums[curr]*(n - curr - 1);}

            ans = min(ans, cost);

            i = curr;
        }

        return ans;
    }
};