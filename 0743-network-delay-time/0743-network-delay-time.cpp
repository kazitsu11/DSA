class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<vector<int>>>adj(n+1);
        vector<int>dist(n+1,INT_MAX);

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;

        for(auto& e:times){
            int u=e[0];
            int v=e[1];
            int w=e[2];
            adj[u].push_back({v,w});
        }

        dist[k]=0;
        pq.push({0,k});

        while(!pq.empty()){
            auto curr=pq.top();
            int d=curr[0];
            int node=curr[1];
            pq.pop();

            for(auto &neigh:adj[node]){
                int adjNode=neigh[0];
                int wt=neigh[1];

                if(d+wt<dist[adjNode]){
                    dist[adjNode]=d+wt;
                    pq.push({d+wt,adjNode});
                }
            }
        }
        int ans=*max_element(dist.begin()+1,dist.end());
        if(ans==INT_MAX) return -1;
        return ans;
        //return -1 :INT_MAX?ans
    }
};