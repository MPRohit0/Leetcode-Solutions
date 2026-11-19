class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int ans = 0;

        //with s2
        int i = 0, j = 0;
        string curr_string_a = ""; 
        while(i < s1.size() && j < s2.size()){
            if(s1[i] == s2[j]){
                curr_string_a += s1[i];
            }else{
                break;
            }
            i++; j++;
        }
        //with s3
        i = 0, j = 0;
        string curr_string_b = "";
        while(i < curr_string_a.size() && j < s3.size()){
            if(curr_string_a[i] == s3[j]){
                curr_string_b += s1[i];
            }else{
                break;
            }
            i++; j++;
        }
        ans += s1.size() + s2.size() + s3.size() - 3 * curr_string_b.size();

        return (curr_string_b.size() == 0)? -1: ans;
    }
};