class Solution {
public:
    int sumCounts(vector<int>& nums) {
        
        int ans = 0;

        for(int i = 0; i < nums.size(); i++){
            unordered_set <int> lol;
            int curr = 0;
            for(int j = i; j < nums.size(); j++){
                
                if(!lol.count(nums[j])){
                    lol.insert(nums[j]);
                    curr++;
                }
                ans += curr * curr;
            }
        }

        return ans;
    }
};