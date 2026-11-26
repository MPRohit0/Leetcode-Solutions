class Solution {
public:
    int compress(vector<char>& chars) {
        
        int ans = 0;
        for(int i = 0; i < chars.size(); i++){            
            int curr = i;
            char c = chars[i];
            if(c == '\t') continue;
            
            int freq = 0;
            while(curr < chars.size() && chars[curr] == c){
                freq++; curr++;
            }

            if(freq == 1){continue;}
            else{
                stack<char> num;
                while(freq > 0){
                    num.push('0' + freq%10); 
                    freq /= 10;
                }

                //change values.
                for(int s = i + 1; s < curr; s++){
                    if(num.empty()){
                        chars[s] = '\t';
                    }else{
                        chars[s] = num.top();
                        num.pop();
                    }
                }
            }
            i = curr - 1;
        }

        for(char c: chars){
            cout << c;
        }
        cout << '\n';

        // cleaning the array and return the size
        int w = 0;
        for(int r = 0; r < chars.size(); r++){
            while(w < chars.size() && chars[w] != '\t'){
                w++;
            }
            
            if(w < r && chars[r] != '\t'){
                swap(chars[w], chars[r]);
                w++;
            }
        }

        for(char c: chars){
            cout << c;
        }

        return w;
        
    }
};