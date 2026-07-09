class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    void Disjoint(int n) {
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        rank.resize(n, 0);
    }

    int findPar(int node) {
        if (parent[node] == node) {
            return node;
        } else
            return parent[node] = findPar(parent[node]);
    }
    void setRank(int u, int v) {
        int ult_u = findPar(u);
        int ult_v = findPar(v);
        if (ult_u == ult_v) {
            return;
        }
        if (rank[ult_u] > rank[ult_v]) {
            parent[ult_v] = ult_u;
        } else if (rank[ult_v] > rank[ult_u]) {
            parent[ult_u] = ult_v;
        } else {
            parent[ult_v] = ult_u;
            rank[ult_u]++;
        }
    }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,vector<vector<int>>& queries) {

        vector<bool> exist;
        Disjoint(n);
        for(int i=0;i<n-1;++i){
            if(nums[i+1]-nums[i]<=maxDiff){
                setRank(i,i+1);
            }
        }

        for (auto& q : queries) {
            int u = q[0];
            int v = q[1];

            if (findPar(u) == findPar(v) ) {
                exist.push_back(true);
            } else
                exist.push_back(false);
        }
        return exist;
    }
};