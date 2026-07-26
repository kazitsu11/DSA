class Solution {
public:
    int largestInteger(int n, int s) {
        vector<int>ans;
        string res;
        int d;
        for(int i=9;i>=0;--i){
            ans.push_back(i);
        }
        if(s==0){
            return 0;
        }
        if(n<2 && s<=9){
            return s;
        }
       while(n--){
       int digit=min(9,s);
       res.push_back('0'+digit);
       s-=digit;
       }
       if(s==0)
       return d=stoi(res);

       return -1;
    }
};