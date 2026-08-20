class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1;
        vector<int> arr2;

        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(arr1.empty()){
                arr1.push_back(nums[i]);
            }else if(arr2.empty()){
                arr2.push_back(nums[i]);
            }else{
                if(arr1.back() > arr2.back()) arr1.push_back(nums[i]);
                else arr2.push_back(nums[i]);
            }
        }

        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        return arr1;
    }
};