class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int ans = 0;

        int j = 0;
        int val = 0;
        for(int i = 0; i < s.size(); i++){
            if(vowels.count(s[i])){ val++;}

            while(i - j + 1 > k){
                if(vowels.count(s[j++])){ val--;}
            }

            ans = max(ans, val);
        }

        return ans;
    }
};