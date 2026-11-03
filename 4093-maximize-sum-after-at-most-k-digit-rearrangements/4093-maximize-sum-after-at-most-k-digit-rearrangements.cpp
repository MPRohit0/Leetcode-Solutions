class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        long long ans = accumulate(nums.begin(), nums.end(), 0LL);
        priority_queue<int, vector<int>, greater<int>> pq;
        
        //min heap for the diff
        for(int i: nums){
            string a = to_string(i);
            sort(a.begin(), a.end(), greater<char>());
            int diff = stoi(a) - i;

            if(pq.size() >= k){
                if(pq.top() < diff){
                    pq.pop(); pq.push(diff);
                }
            }else{
                pq.push(diff);
            }

        }

        while(!pq.empty()){
            ans += (long long)pq.top();
            pq.pop();
        }

        return ans;

    }
};