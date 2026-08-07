class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashmap;

        for(string str: strs){
            string count(26,'0');
            for(char c: str){
                count[c-'a']++;
            }

            hashmap[count].push_back(str);
        }

        vector<vector<string>> ans;
        for(auto& pa: hashmap){
            ans.push_back(pa.second);
        }

        return ans;

    }
};