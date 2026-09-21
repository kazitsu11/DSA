class Solution {
public:
vector<vector<int>>directions={{-1,0},{1,0},{0,-1},{0,1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<int,int>>q;

        vector<vector<int>>dist(n,vector<int>(m,-1));

        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(mat[i][j]==0){
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();

            for(auto& dir:directions){
                int new_i=i+dir[0];
                int new_j=j+dir[1];

                if(new_i>=0 && new_j>=0 && new_i<n && new_j<m && dist[new_i][new_j]==-1){
                    dist[new_i][new_j]=dist[i][j]+1;
                    q.push({new_i,new_j});
                }
            }
        }
        return dist;
    }
};