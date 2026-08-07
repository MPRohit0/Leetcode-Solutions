class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n = flowers.size();

        vector<int> start(n);
        vector<int> stop(n);
        for(int i = 0; i < n; i++){
            start[i] = flowers[i][0];
            stop[i] = flowers[i][1];
        }

        sort(start.begin(), start.end());
        sort(stop.begin(), stop.end());

        vector<int> ans;
        for(int i: people){
            int t = -1;

            int s = 0, e = n-1;
            while(e >= s){
                int mid = s + (e-s)/2;

                if(start[mid] > i){
                    t = mid;
                    e = mid - 1;
                }
                else s = mid + 1;
            }
            t = (t == -1)? (e+1) : t;

            int k = -1;
            s = 0, e = n-1;
            while(e >= s){
                int mid = s + (e-s)/2;

                if(stop[mid] >= i){
                    k = mid;
                    e = mid - 1;
                }
                else{
                    s = mid + 1;
                }
            }
            k = (k == -1)? (e+1) : k;

            ans.push_back(t-k);
            cout << t << " " << k << "\n";
        }
        return ans;
    }
};