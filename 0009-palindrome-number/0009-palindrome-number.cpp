class Solution {
public:
    bool isPalindrome(int x) {
        string a = to_string(x);

        int s = 0, e = a.size()-1;

        while(s<e){
            if(a[s++] != a[e--]){
                return false;
            }
        }
        return true;

    }
};