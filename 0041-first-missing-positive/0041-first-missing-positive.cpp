class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        //our answer is in the range [1,n+1]

        //cyclic sort varient
        int i = 0;
        while(i<n){
            if(nums[i]>0 && nums[i]<=n && nums[i] != nums[nums[i]-1]){
                swap(nums[nums[i]-1],nums[i]);
            }else{
                i++;
            }
        }

        for(int i:nums) cout<<i<<" ";
        cout<<"\n";

        //pass
        for(int i = 0; i<n; i++){
            if(nums[i] != i+1){
                return (i+1);
            }
        }

        return n+1;
    }
};