class Solution {
public:
    int countDominantElements(vector<int>& nums) {
        
        int ans = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            vector<int> l;
            if(i > 0){l.push_back(nums[i-1]);}
            if(i < n-1){l.push_back(nums[i+1]);}

            float avg = 0;
            for(float i: l){avg += i;}
            if(l.size() > 0) avg /= l.size();

            if(avg <= nums[i]) ans++; 
        }

        return ans;
    }
};