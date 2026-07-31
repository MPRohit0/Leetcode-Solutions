class Solution {
public:
    void bt(int n, int k, int i, int cost,string& temp, vector<string>& ans){
        if(cost > k) return;
        if(i == n){
            ans.push_back(temp);
            return;
        }

        //0
        temp += '0';
        bt(n, k, i+1, cost, temp, ans);
        temp.pop_back();

        //1
        if(temp.empty() || temp.back() != '1'){
            temp += '1';
            bt(n, k, i+1, cost+i, temp, ans);
            temp.pop_back();
        }
    }

    vector<string> generateValidStrings(int n, int k) {
        vector<string> ans; 
        string t;

        bt(n, k, 0, 0, t, ans);
        return ans;

    }
};