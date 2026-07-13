class Solution {
public:
    vector<int> parent, rank;
    void disjoint(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
    int findPar(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findPar(parent[node]);
    }

    void rankUnion(int u, int v) {
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
    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();
        int sum = 0;
        vector<vector<int>> edges;
        disjoint(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dis = abs(x1 - x2) + abs(y2 - y1);
                edges.push_back({dis, i, j});
            }
        }
        sort(edges.begin(), edges.end());
        for (auto& edge : edges) {
            int w = edge[0];
            int u = edge[1];
            int v = edge[2];

            if (findPar(u) != findPar(v)) {
                rankUnion(u, v);
                sum += w;
            }
        }

        return sum;
    }
};