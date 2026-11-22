class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        
        int prev_neg = 0;
        int prev_pos = 0;

        int max_prod = INT_MIN;

        for(int i = 0; i < n; i++){
            max_prod = max(max_prod, nums[i]);

            if(nums[i] > 0){ //positive number
                prev_neg = prev_neg * nums[i];
                prev_pos = max(prev_pos, 1) * nums[i];   
                
                max_prod  = max(max_prod, prev_pos);             
            }else if(nums[i] < 0){ //negative number
                int pos = prev_neg * nums[i]; 
                int neg = min( (prev_pos) * nums[i], nums[i]); 
                
                prev_pos = pos; 
                prev_neg = neg;    
            }else{
                prev_pos = 0;
                prev_neg = 0;
            }

            max_prod = max(max_prod, prev_pos);
        }

        return max_prod;
    }
};