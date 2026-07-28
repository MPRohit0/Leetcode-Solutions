class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector <int> ans;
        
        //lower
        int low = -1;
        int s = 0, e = nums.size()-1;

        while(s<=e){
            int mid = s + (e-s)/2;
            if(nums[mid]==target){
                low = mid;
                e = mid - 1;
            }else if(nums[mid]>target){
                e = mid - 1;
            }else s = mid+1;
        }
        ans.push_back(low);
        

        //upper
        int high = -1;
        s = 0, e = nums.size()-1;

        while(s<=e){
            int mid = s + (e-s)/2;
            if(nums[mid]==target){
                high = mid;
                s = mid + 1;
            }else if(nums[mid]>target){
                e = mid -1;
            }else{
                s = mid +1;
            }
        }
        ans.push_back(high);

        return ans;
    }
};