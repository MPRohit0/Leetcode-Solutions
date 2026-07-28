class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        
        for(int i=0;i<nums.size();i++){
            if(i>0&&nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<nums.size();j++){
                if(j-1>i && nums[j]==nums[j-1]) continue;
                int s = j+1, e = nums.size()-1;
                while(s<e){
                    long long int sum = (long long int) nums[i]+nums[j]+nums[s]+nums[e];
                    if(sum==target){
                        ans.push_back(vector<int>{nums[i],nums[j],nums[s],nums[e]});
                        s++;
                        e--;

                        while(s<e && nums[s]==nums[s-1]) s++;
                        while(s<e && nums[e]==nums[e+1]) e--;
                    }else if(sum >target){
                        e--;
                    }else{
                        s++;
                    }
                }
            }
        }
        return ans;
    }
};