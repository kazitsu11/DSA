class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
       
        vector<vector<pair<int,int>>> adj(n+1);
        vector<int>dist(n+1,INT_MAX);

        for(auto &node:roads){
            int u=node[0];
            int v=node[1];
            int d=node[2];

            adj[u].push_back({d,v});
            adj[v].push_back({d,u});
        }

        pq.push({INT_MAX,1});

        while(!pq.empty()){
            auto[d,c]=pq.top();
            pq.pop();

            for(auto & vec:adj[c]){
                int node=vec.second;
                int wt=vec.first;
                int new_d=min(d,wt);
                if(new_d<dist[node]){
                    dist[node]=new_d;
                    pq.push({new_d,node});
                }
            }
        }
         int ans=*min_element(dist.begin(),dist.end());

         return ans;
    }
};