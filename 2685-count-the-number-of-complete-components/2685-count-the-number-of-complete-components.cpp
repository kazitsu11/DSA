class Solution {
public:
    vector<int> parent, rank;
    void Disjoint(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int findPar(int node) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = findPar(parent[node]);
    }

    void RankUnion(int u, int v) {
        int ult_u = findPar(u);
        int ult_v = findPar(v);

        if (ult_u == ult_v) {
            return;
        }
        if (rank[ult_u] > rank[ult_v]) {
            parent[ult_v] = ult_u;
        } 
        else if (rank[ult_v] > rank[ult_u]) {
            parent[ult_u] = ult_v;
        } 
        else {
            parent[ult_v] = ult_u;
            rank[ult_u]++;
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        Disjoint(n);
        int k=0;
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
             RankUnion(u,v);
        }
        unordered_map<int,int>nodecount;
        unordered_map<int,int>edgecount;

            for(int i=0;i<n;++i){
               int root=findPar(i);
               nodecount[root]++;
            }

            for(auto & e:edges){
                int root=findPar(e[0]);
                edgecount[root]++;
            }
         for(auto& it:nodecount){
            int root=it.first;
            int node=it.second;

            int edge=edgecount[root];

            if(edge==node*(node-1)/2){
                k++;
            }
         }
            
        return k;
    }
};