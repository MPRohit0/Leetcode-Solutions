class Solution {
public:
    int maxDistance(string moves) {
        int i = 0;
        int j = 0;
        int ans = 0;

        for(char c: moves){
            if(c == 'L') j--;
            else if(c == 'R') j++;
            else if(c == 'U') i--;
            else if(c == 'D') i++;
            else ans++;
        }

        ans += abs(i) + abs(j);
        return ans;
    }
};