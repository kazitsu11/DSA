class Solution {
public:

void dfs(int i,vector<vector<int>>&adj,vector<int>&vis){
    
    vis[i]=1;
    for(auto&neigh:adj[i]){
        if(!vis[neigh])
        dfs(neigh,adj,vis);
    }
}
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
         vector<int>vis(n,0);
        

        for(auto& e:invocations){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
        }
       
        dfs(k,adj,vis);
        
        for(auto& e:invocations){
            int u=e[0];
            int v=e[1];
            if(vis[u]==0  &&  vis[v]==1){
                 vector<int>ans;
              for(int i=0;i<n;++i){
                ans.push_back(i);
              }
              return ans;
            }
        }
        
     vector<int>ans;
        for(int i=0;i<n;++i){
            if(vis[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};