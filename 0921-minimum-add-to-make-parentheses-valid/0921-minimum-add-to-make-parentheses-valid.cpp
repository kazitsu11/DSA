class Solution {
public:
    int minAddToMakeValid(string s) {
        int open=0;
        int close=0;
        int need=0;
        for(auto& c:s){
            if(c=='(') open++;
            else if(c==')'){
                if(open>0){
                    open--;
                }
                else need++;
            }
        }
         return need+open;
    }
};