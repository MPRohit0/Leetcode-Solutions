class Solution {
public:
    bool detectCapitalUse(string word) {
        bool small = false;
        bool cap = false;

        for(int i = 1; i < word.size(); i++){
            if(small && cap) break;

            if(word[i] >= 'a' && word[i] <= 'z') small = true;
            else cap = true;
        }

        if(small && cap) return false;
        if(cap){
            return word[0] >= 'A' && word[0] <= 'Z';
        }else{
            return true;
        }
        
    }
};