class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        
        int n = s.size();
        int ones = 0;

        for(char c: s){
            if(c == '1') ones++;
        }

        ones--;
        for(int i = 0;i < n; i++){
            if(ones > 0){
                s[i] = '1';
                ones--;
            }else{
                s[i] = '0';
            }
        }
        s.back() = '1'; 

        return s;
        
    }
};