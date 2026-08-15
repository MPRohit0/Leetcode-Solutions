class Solution {
public:
    string reverseVowels(string s) {
        unordered_set <char> vow= {'A','E','I','O','U','a','e','i','o','u'};

        int n = s.size();


        int start = 0;
        int end = n-1;

        while(end>=start){
            //s
            while(start<n && !vow.count(s[start])) start++;
            while(end >=0 && !vow.count(s[end])) end--;

            if(start < end)
                swap(s[start],s[end]);
            start++; end--;
        }

        return s; 
    }
};