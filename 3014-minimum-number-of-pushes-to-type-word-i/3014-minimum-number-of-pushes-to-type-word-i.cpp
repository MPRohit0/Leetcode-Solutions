class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int ans = 0; int i = 1;
        while(n > 0){
            if(n - 8 < 0){
                ans += i*(n);
                return ans;
            }
            ans += i*(8);
            n -= 8;
            i++;
        }

        return ans;
    }
};