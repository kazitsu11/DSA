class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        vector<int>res;

        for(auto& a:nums){
            mp[a]++;
        }

        for(auto & p:mp){
            int freq=p.second;

            if(freq>n/3){
                res.push_back(p.first);
            }
        }
        return  res;
    }
};