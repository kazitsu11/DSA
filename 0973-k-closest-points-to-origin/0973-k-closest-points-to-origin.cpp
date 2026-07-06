class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>>pq;
       vector<vector<int>> ans;
        for(auto& curr:points){
            int dist=curr[0]*curr[0]+curr[1]*curr[1];
            pq.push({dist,curr});
            if(pq.size()>k){
                 pq.pop();
            }
        }
        while(!pq.empty()){
         ans.push_back(pq.top().second);
         pq.pop();
        }
         return ans;
    }
};