class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int total_xor=0;
        int zero=0;


        for(auto& a:nums){
            total_xor^=a;

            if(a==0) zero++;
        }

        if(total_xor!=0) return n;
        else{
           if( zero==n ) return 0;
            
            return n-1;
        }
    }
};