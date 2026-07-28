class Solution {
public:
    bool isOpen(char t){ 
        char open[3] ={'(','{','['}; 
        for(int i =0;i<3;i++){ 
            if(t==open[i]) return true; 
        } 
        return false; 
    }

    bool isValid(string s) {
        stack <char> save;
        unordered_map<char,char> converter = {{')','('},{']','['},{'}','{'}};

        for(char i: s){
            if(isOpen(i)){
                save.push(i);
            }else{
                if(!save.empty()&&save.top()==converter[i]){
                    save.pop();
                }else{
                    return false;
                }
            }
        }

        if(save.empty()){
            return true;
        }else{
            return false;
        }
        return true;
    }
};