class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int total_xor=0;
        unordered_map<int,int>mp;

        for(auto&a:nums){
            mp[a]++;
        }

        for(auto& a:nums){
            total_xor^=a;
        }

        if(total_xor!=0) return n;
        else{
           if( mp.size()==1 && mp.begin()->first==0) return 0;
            
            return n-1;
        }
    }
};