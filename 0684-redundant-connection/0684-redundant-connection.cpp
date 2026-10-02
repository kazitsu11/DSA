class Solution {
public:
vector<int>parent,rank;
void disjoint(int n){
    parent.resize(n);
    rank.resize(n,0);
    
    for(int i=0;i<n;++i){
        parent[i]=i;
    }
}

int findpar(int node){
    if(node==parent[node]){
        return node;
    }
    return parent[node]=findpar(parent[node]);
}

void RankUnion(int u,int v){
    int ul_u=findpar(u);
    int ul_v=findpar(v);

    if(ul_u==ul_v){
        return;
    }
    if(rank[ul_u]>rank[ul_v]){
        parent[ul_v]=ul_u;
    }
    else if(rank[ul_v]>rank[ul_u]){
        parent[ul_u]=ul_v;
    }
    else{
        parent[ul_v]=ul_u;
        rank[ul_u]++;
    }
}
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        disjoint(n+1);

        for(auto& e:edges){
            int u=e[0];
            int v=e[1];

            if(findpar(u)==findpar(v)){
                return e;
            }
            RankUnion(u,v);
        }
        return {};
    }
};
