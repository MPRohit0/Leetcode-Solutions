class Solution {
public:
    double myPow(double x, int n) {
        
        long int N = n;

        if(N<0){
           x = 1/x;
            N = -N;
        }
        
        
        double ans=1;
        while(N){
            if(N%2==1){
                ans *=x;
            }
            x = x*x;
            N /=2;
        }
        return ans;
    }
};