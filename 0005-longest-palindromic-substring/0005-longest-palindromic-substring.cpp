class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.size();
        int a = 0, b = 0;

        //odd
        for(int i = 0; i < n; i++){
            int l = i, r = i;
            while(l >=0 && r<n && s[l] == s[r]){
                l--; r++;
            }
            l++; r--;
            if(b - a < r - l){
                b = r; a = l;
            }
        }

        //even
        for(int i = 0; i < n; i++){
            int l = i, r = i+1;
            while(l >=0 && r<n && s[l] == s[r]){
                l--; r++;
            }
            l++; r--;
            if(b - a < r - l){
                b = r; a = l;
            }
        }


        // cout<< a << b <<"\n";
        return s.substr(a, (b-a + 1));
    }
};