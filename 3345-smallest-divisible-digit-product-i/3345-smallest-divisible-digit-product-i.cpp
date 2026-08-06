class Solution {
    bool eval(int n, int t){
        int k = 1;
        while(n){
            k *= n%10;
            n /= 10;
        }
        return (k%t);
    }
public:
    int smallestNumber(int n, int t) {
        while(eval(n,t)){
            n++;
        }

        return n;
    }
};