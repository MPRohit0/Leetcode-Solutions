class Solution {
public:
    bool threeFibonacciSum(int n) {
        if(n%2 == 1) return false;

        n /= 2;

        //check if n is fib or not
        int a = 0, b = 1;
        while(b <= n){
            if(b == n) return true;

            int c = a + b;
            a = b;
            b = c;
        }

        return false;

    }
};