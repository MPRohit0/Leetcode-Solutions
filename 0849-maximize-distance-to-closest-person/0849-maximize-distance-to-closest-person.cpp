class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        //get max size of contineous 0's
        
        int ans = 0;

        int prev = -1;

        for(int i = 0; i < seats.size(); i++){
            if(seats[i] == 1){
                if(prev == -1) ans = i;
                else{
                    ans = max(ans, (i - prev)/2);
                }
                prev = i;
            }
        }

        ans = max(ans, (int)seats.size() - 1 - prev);

        return ans;
    }
};