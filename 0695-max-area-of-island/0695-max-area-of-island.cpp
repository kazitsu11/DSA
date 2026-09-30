class Solution {
public:
vector<vector<int>>directions={{-1,0},{1,0},{0,-1},{0,1}};
int dfs(int i,int j,vector<vector<int>>&grid, vector<vector<bool>>&vis,int n,int m){
    if(grid[i][j]==0) return 0;
    int area=1;

    for(auto& dir:directions){
        int new_i=i+dir[0];
        int new_j=j+dir[1];

        if(new_i>=0 && new_j>=0 && new_i<n && new_j<m && grid[new_i][new_j]==1 && vis[new_i][new_j]==false){
            vis[new_i][new_j]=true;
            area+=dfs(new_i,new_j,grid,vis,n,m);
        }
    }
    return area;
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int ans=0;

        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]==1 && vis[i][j]==false){
                    vis[i][j]=true;
                    ans=max(ans,dfs(i,j,grid,vis,n,m));
                }
            }
        }
        return ans;
    }
};