class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int n1 = haystack.size(), n2 = needle.size();
        for(int i = 0; i < (n1-n2+1); i++){
            if(haystack[i] == needle[0]){
                if(haystack.substr(i,n2) == needle){
                    return i;
                }
            }
        }
        return -1;
    }
};