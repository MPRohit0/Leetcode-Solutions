class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {

        int n = 100;        
        vector<int> lol(n+1,0);

        for(int i: nums){
            lol[i]++;
        }

        for(int &i: lol){
            if(i > 1) i = 0;
        }

        for(int i:nums){

            if(lol[i] && i%2 == 0){
                return i;
            }
        }

        return -1;
    }
};