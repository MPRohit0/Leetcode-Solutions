class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> x = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};

        unordered_map<char,int> lol;
        int a = 0;
        for(string word: x){
            for(char j: word){
                lol[j] = a;
            }
            a++;
        }

        vector<string> ans;
        for(string word: words){
            int level = -1;
            bool valid = true;
            for(int i = 0; i < word.size(); i++){
                if(level == -1){
                    level = lol[tolower(word[i])];
                }else{
                    if(level != lol[tolower(word[i])]){
                        valid = false;
                        break;
                    }
                }
            }
            if(valid) ans.push_back(word);
        }

        return ans;
    }
};