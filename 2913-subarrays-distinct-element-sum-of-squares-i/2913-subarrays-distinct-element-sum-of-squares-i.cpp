class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>res;

        for(int i=0;i<n;++i){
            for(int j=i;j<n;++j){
                
                vector<int>ans;

                for(int k=i;k<=j;++k){
                    ans.push_back(nums[k]);
                }
                res.push_back(ans);
            }
        }
      
      int sum=0;
        for(auto& a:res){
            unordered_set<int>st;

            for(int i=0;i<a.size();++i){
                st.insert(a[i]);
            }
            sum+=st.size()*st.size();
        }
        return sum;
    }
};