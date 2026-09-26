class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>>adj(n+1);
        vector<int>in(n+1,0);
        vector<int>out(n+1,0);


        for(auto& e:trust){
            adj[e[0]].push_back(e[1]);
            in[e[1]]++;
            out[e[0]]++;
        }

        for(int i=1;i<n+1;++i){
            if(out[i]==0 && in[i]==n-1)return i;
        }
        return -1;
    }
};