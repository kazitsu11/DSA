class Solution {
public:
bool solve(vector<int>&matchsticks,vector<int>&sides,int target,int idx){
    if(idx==matchsticks.size()){
        return sides[0]==target && sides[1]==target && sides[2]==target && sides[3]==target;
    }

    for(int i=0;i<4;++i){
        if(sides[i]+matchsticks[idx]>target)continue;
        if(i>0 && sides[i]==sides[i-1]) continue;
        sides[i]+=matchsticks[idx];
        if(solve(matchsticks,sides,target,idx+1))  return true;
        sides[i]-=matchsticks[idx];
    }
    return false;
}
    bool makesquare(vector<int>& matchsticks) {
        int n=matchsticks.size();
        int sum=0;
        for(auto& a:matchsticks){
            sum+=a;
        }
        int target=sum/4;
        vector<int>sides(4,0);
        return solve(matchsticks,sides,target,0);
    }
};