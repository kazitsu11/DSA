class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
         unordered_map<int,int>mp;
       
        for(auto& a:arr){
            mp[a]++;
        }
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