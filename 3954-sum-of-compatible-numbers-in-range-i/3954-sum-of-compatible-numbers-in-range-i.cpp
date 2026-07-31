class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int s = (n-k) < 0 ? 0 : n - k;
        int e = n + k;

        int ans = 0;
        for(int i = s; i <= e; i++){
            if((i & n) == 0){
                ans += i;
            }
        }

        return ans;
    }
};