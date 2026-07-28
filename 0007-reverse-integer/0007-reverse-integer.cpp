class Solution {
public:
    int reverse(int x) {
        if(x == INT_MIN) return 0;

        bool neg = false;
        if(x<0){
            neg = true;
            x = -x;
        }
        
        long c = 0;
        while(x>0){
            c += x%10;

            c*=10;
            x/=10;
        }
        c/=10;

        if((!neg && c>INT_MAX) || (neg && (-c)<INT_MIN)){
            return 0;
        }
        
        return neg? -c:c;

    }
};