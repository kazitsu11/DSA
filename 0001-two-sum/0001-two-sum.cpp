class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        int n=nums.size();
        vector<int>ans;

        for(int i=0;i<n;++i){
            int compliment=target-nums[i];
            if(mp.find(compliment)==mp.end()){
                mp[nums[i]]=i;
            }
            else{
                ans.push_back(i);
                ans.push_back(mp[compliment]);
            }
        }
        return ans;
    }
};