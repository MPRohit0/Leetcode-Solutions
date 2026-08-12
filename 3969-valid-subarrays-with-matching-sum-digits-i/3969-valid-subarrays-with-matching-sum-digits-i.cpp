class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            long long sum = 0;
            for(int j = i; j < n; j++){
                sum += nums[j];

                //valid;
                long long t = sum;
                int l = sum%10;
                while(t >= 10) t/=10;
                int r = t;
                if(r == x && l == x) ans++;
            } 
        }

        return ans;
    }
};