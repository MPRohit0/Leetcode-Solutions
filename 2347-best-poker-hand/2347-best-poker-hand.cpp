class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        if((unordered_set<char> (suits.begin(),suits.end())).size() == 1) return "Flush";

        unordered_map<int,int> freq;
        for(int i: ranks){
            freq[i]++;
        }

        int a = 0;
        for(auto &[c, i] : freq){
            a = max(a,i);
        }

        if(a >= 3) return "Three of a Kind";
        else if(a == 2) return "Pair";
        
        return "High Card";
    }
};