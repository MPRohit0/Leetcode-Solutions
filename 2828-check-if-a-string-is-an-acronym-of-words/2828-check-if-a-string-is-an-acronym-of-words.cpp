class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        int n = words.size();
        int m = s.size();

        if(n != m) return false;

        int i = 0, j = 0;
        while(i < n && j < m){
            if(words[i][0] != s[j]) return false;
            i++; j++;
        }
        return true;
    }
};