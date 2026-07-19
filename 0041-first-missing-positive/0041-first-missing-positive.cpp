class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto& a:nums){
            mp[a]++;
        }
       
       int k=1;
       int curr=1;
       while(k>0){
        if(mp[curr]==0){
            k--;
        }
        curr++;
       }
       return curr-1;
    }
};