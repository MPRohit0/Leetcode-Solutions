class Solution {
public:
    string helper(char i){
        map<char,string> lol = {{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
        return lol[i];
    }

    void com(string& digits, string& temp, vector<string>& ans, int idx){
        if(idx==digits.size()){
            ans.push_back(temp);
            return;
        }

        for(char i: helper(digits[idx])){
            temp.push_back(i);
            com(digits,temp,ans,idx+1);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        string temp;
        vector<string> ans;
        com(digits,temp,ans,0);
        return ans;
    }
};