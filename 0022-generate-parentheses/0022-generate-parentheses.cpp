class Solution {
public:
    void par(string& temp,vector<string>& ans,int open,int close,int n){
        if(close + open==2*n){
            ans.push_back(temp);
            return;
        }

        if(open<n){
            temp.push_back('(');
            par(temp,ans,open+1,close,n);
            temp.pop_back();
        }

        if(open>close){
            temp.push_back(')');
            par(temp,ans,open,close+1,n);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        par(temp,ans,0,0,n);
        return ans;    }
};