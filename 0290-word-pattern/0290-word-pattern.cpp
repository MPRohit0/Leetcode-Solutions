class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        int left = 0;
        int i = 0;
        unordered_map<char,string> hashmap;
        unordered_set<string> a;
        for(int right = 0; right < s.size(); right++){
            if(right == s.size()-1 || s[right+1] == ' '){
                if(hashmap.count(pattern[i])){
                    if(hashmap[pattern[i]] != s.substr(left,right-left+1)){
                        return false;
                    }
                }else{
                    hashmap[pattern[i]] = s.substr(left,right-left+1);
                    if(a.count(hashmap[pattern[i]])) return false;
                    a.insert(hashmap[pattern[i]]);
                    
                }
                left = right + 2;
                i++;
            }
        }
        return i == pattern.size();
    }
};