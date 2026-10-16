class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> lol (nums1.begin(), nums1.end());
        unordered_set<int> lol2 (nums2.begin(), nums2.end());
        
        vector<int> ans;
        
        for(int i: lol2){
            if(lol.count(i)) ans.push_back(i);
        }

        return ans;
    }
};