class Solution {
public:

vector<vector<int>>directions={{-1,0},{1,0},{0,-1},{0,1}};
bool dfs(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>&vis){
    int n=grid.size();
    int m=grid[0].size();
    
    bool touchboundary=(i==0 || i==n-1 || j==0 || j==m-1);
    for(auto& dir:directions){
        int new_i=i+dir[0];
        int new_j=j+dir[1];

        if(new_i>=0 && new_j>=0 && new_i<n && new_j<m && grid[new_i][new_j]==0 && vis[new_i][new_j]==false){
          vis[new_i][new_j]=true;
          if(dfs(new_i,new_j,grid,vis)){
            touchboundary=true;
          }
        }
    }
    return touchboundary;
}
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int count=0;
        
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]==0 && vis[i][j]==false){
                    vis[i][j]=true;
                    if(dfs(i,j,grid,vis)==false){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};