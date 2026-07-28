class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int read = 0;
        int write = 0;

        int k = 0;

        while(read < nums.size() && write < nums.size()){
            if(nums[read]== val){
                while(write<read) write++;
                
                if(nums[write] == val){
                    write++;
                    continue;
                }else{
                    k++;
                    swap(nums[read],nums[write]);
                    read++;
                }
            }else{
                    read++;
            }
        }

        return read;
    }
};