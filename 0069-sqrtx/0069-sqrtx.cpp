class Solution {
public:
    int mySqrt(int x) {



        int s = 0, e = x;

        while(e>=s){
            long long int mid = s + (e-s)/2;
            if(mid*mid > x){
                e = mid-1;
            }else{
                s = mid + 1;
            }
        }

        return s-1;
    }
};