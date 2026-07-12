class Solution {
public:
vector<int> rank,parent;
void disjoint(int n){
rank.resize(n,0);
parent.resize(n);
for(int i=0;i<n;i++){
    parent[i]=i;
}
}
int findPar(int node){
    if(node==parent[node]){
        return node;
    }
    return parent[node]=findPar(parent[node]);
}
void rankUnion(int u,int v){
    int ul_u=findPar(u);
    int ul_v=findPar(v);
    if(ul_u==ul_v){
        return;
    }
    if(rank[ul_u]>rank[ul_v]){
        parent[ul_v]=ul_u;
    }
    if(rank[ul_v]>rank[ul_u]){
        parent[ul_u]=ul_v;
    }
    else{
        parent[ul_v]=ul_u;
        rank[ul_u]++;
    }
}
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
      disjoint(n);

      for(auto& edge:edges){
        int u=edge[0];
        int v=edge[1];

        rankUnion(u,v);
        
      }

      if(findPar(source)==findPar(destination)){
        return true;
      }
      return false;

    }
};