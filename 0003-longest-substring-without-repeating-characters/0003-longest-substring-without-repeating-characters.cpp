class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> lol;
        
        int n = s.size();
        int l = 0, r = 0;
        int len = 0;

        while(r<n){
            if(lol.count(s[r])){
                lol.erase(s[l]);
                l++; 
            }else{
                
                lol.insert(s[r]);
                if(len < (r-l+1)) len = r - l + 1;
                r++;
            }
        }

        return len;
    }
};