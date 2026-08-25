class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_set<int>st;
        
        for(auto& a:nums){
            st.insert(a);
        }
        for(int i=0;i<=n;++i){
            if(st.find(k*(i+1))==st.end()){
                return k*(i+1);
            }
        }
        return 0;
    }
};