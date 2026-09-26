class Solution {
public:
vector<vector<int>>directions={{-1,0},{1,0},{0,-1},{0,1}};
int dfs(int i,int j, vector<vector<int>>&grid,vector<vector<int>>&vis){
    int n=grid.size();
    int m=grid[0].size();
    int peri=0;

     for(auto &dir:directions){
        int new_i=i+dir[0];
        int new_j=j+dir[1];

            if(new_i<0 || new_i>=n || new_j<0 || new_j>=m) peri++;
            else if(grid[new_i][new_j]==0) peri++;
            else if(grid[new_i][new_j]==1 && vis[new_i][new_j]==0){
                vis[new_i][new_j]=1;
                peri+=dfs(new_i,new_j,grid,vis);
            }
     }
     return peri;
}
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]==1 && vis[i][j]==0){
                    vis[i][j]=1;
                  return dfs(i,j,grid,vis);
                }
            }
        }
        return 0;
    }
};