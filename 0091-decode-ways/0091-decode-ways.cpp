class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();

        int p2 = 1, p1 = 1;
        int c = 0;
        for(int i = 0; i < n; i++){
            if(s[i] != '0'){
                c += p1;
            }
            if(i>0 && s[i-1] != 0 && ((s[i-1] == '2' && s[i] <= '6') || (s[i-1] == '1'))){
                c += p2;
            }
            p2 = p1;
            p1 = c;
            c = 0;
        }

        return p1;
    }
};