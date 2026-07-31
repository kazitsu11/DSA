class Solution {
public:
    int maxJump(vector<int>& stones) {
        int ans=0;
        int n=stones.size();
        if(n==2){
            return *max_element(stones.begin(),stones.end());
        }

        for(int i=2;i<n;++i){
           ans=max(ans,stones[i]-stones[i-2]);
        }
        return ans;
    }
};