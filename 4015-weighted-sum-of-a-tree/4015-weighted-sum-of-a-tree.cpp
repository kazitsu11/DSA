class Solution {
public:
    int height;
    void dfs(int root, vector<vector<int>>& adj, int d, vector<int>& depth) {
        depth[root] = d;
        height = max(height, d);

        for (auto& neigh : adj[root]) {
            dfs(neigh, adj, d + 1, depth);
        }
    }
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        //sort(nums.begin(), nums.end());
        int n = parent.size();
        int m = nums.size();

        vector<vector<int>> adj(n);
        for (int i = 0; i < n; ++i) {
            if (parent[i] != -1) {
            adj[parent[i]].push_back(i);
        }
    }
    vector<int> depth(n);
    dfs(0, adj, 0, depth);

    long long weight = 0;

    for (int i = 0; i < n; ++i) {
        weight += 1LL *nums[i] * (height - depth[i] + 1);
    }
    return weight;
}
}
;