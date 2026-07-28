class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int s = 0, e = nums.size()-1;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(nums[mid] == target){
                return true;
            }

            if(nums[s]==nums[e]&&nums[e]==nums[mid]){
                s++;e--;
                continue;
            }

            if(nums[mid]<=nums[e]){ //rhs is sorted
                if(target <= nums[e] && target > nums[mid]){
                        s = mid + 1;
                    }else{
                        e = mid - 1;
                    }
                
            }else{
                if(target >= nums[s] && target < nums[mid]){
                    e = mid - 1;
                }else{
                    s = mid + 1;
                }
            }
        }
        return false;
    }
};