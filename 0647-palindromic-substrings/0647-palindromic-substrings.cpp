class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<int> dp(n + 1);

        for(int i = 0; i < n; i++){
            dp[i]++; //single

            //even pal
            if(i >= 1 && s[i] == s[i-1]){
                int l = i - 1; 
                int r = i;
                while(l >=0 && r < n){
                    if(s[l--] == s[r++]) dp[i]++;
                    else break;
                }
            }

            //odd pal
            if(i >= 2 && s[i] == s[i-2]){
                int l = i-2;
                int r = i;
                while(l >=0 && r < n){
                    if(s[l--] == s[r++])dp[i]++;
                    else break;
                }
            }
        }

        return accumulate(dp.begin(), dp.end(), 0);
     }
};