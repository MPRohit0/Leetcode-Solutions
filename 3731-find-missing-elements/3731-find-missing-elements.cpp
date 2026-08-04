class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int s = *min_element(nums.begin(), nums.end());
        int l = *max_element(nums.begin(), nums.end());

        unordered_set <int> lol(nums.begin(), nums.end());
        vector<int> ans;
        for(int i = s+1; i < l; i++){
            if(!lol.count(i)) ans.push_back(i);
        }

        return ans;
    }
};