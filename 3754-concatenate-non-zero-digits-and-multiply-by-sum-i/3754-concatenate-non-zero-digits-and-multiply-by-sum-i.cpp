class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum=0;
        long long curr=0;
        int e;
        vector<int> ans;
       while(n>0){
        e=n%10;
        n=n/10;
        ans.push_back(e);
       }
       reverse(ans.begin(),ans.end());
       for(auto & a:ans){
        if(a!=0){
            curr=curr*10+a;
        }
        sum+=a;
       }
        return sum*curr;
    }
};