class Solution {
public:
    void bt(unordered_map<int,int>&c, int n, int i, vector<vector<int>>& ans,vector<int>& t){
        if(i == n){
            ans.push_back(t);
            return;
        }

        for(auto &a: c){
            if(a.second == 0) continue;

            t.push_back(a.first);
            a.second--;
            bt(c,n,i+1,ans,t);
            a.second++;
            t.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map <int,int> counter;
        for(int i: nums){
            counter[i]++;
        }

        vector<vector<int>> ans;
        vector<int> t;

        bt(counter, nums.size(), 0, ans, t);

        return ans;
    }
};