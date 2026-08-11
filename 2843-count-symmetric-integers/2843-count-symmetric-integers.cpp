class Solution {
public:

    int countSymmetricIntegers(int low, int high) {

        int ans = 0;

        for(int i = low; i <= high; i++){
            string lol = to_string(i);

            int n = lol.size();
            if(n % 2 == 1) continue;

            int l = 0, r = n - 1;
            int sum_l = 0, sum_r = 0;
            while(l < r){
                sum_l += lol[l++] - '0';
                sum_r += lol[r--] - '0';
            }

            if(sum_l == sum_r) ans++;
        }

        return ans;
    }
};