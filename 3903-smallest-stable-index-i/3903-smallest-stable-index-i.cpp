class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>arr(n);
        for(int i=0;i<n;++i){
            int mxm=*max_element(nums.begin(),nums.begin()+i);
            int mnm=*min_element(nums.begin()+i,nums.end());
            arr[i]=mxm-mnm;
        }
       
        priority_queue<int,vector<int>,greater<int>>pq;

      for(int i=0;i<n;++i){
        if(arr[i]<=k){
            pq.push(i);
        }
      }
      if(pq.size()==0) return -1;
      return pq.top();
    }
};