class Solution {
public:
vector<vector<int>>directions={{-1,0},{1,0},{0,-1},{0,1}};
 void dfs(int i,int j,vector<vector<char>>&grid,vector<vector<int>>&vis,int n,int m){
    if(i<0 ||j<0 ||i>=n ||j>=m){
        return;
    }
     
    if(grid[i][j]=='0'){
        return;
    }
    for(auto& dir:directions){
       int new_i=i+dir[0];
       int new_j=j+dir[1];

       if(new_i>=0 && new_j>=0 && new_i<n && new_j<m && vis[new_i][new_j]==0 && grid[new_i][new_j]=='1'){
        vis[new_i][new_j]=1;
        dfs(new_i,new_j,grid,vis,n,m);
       }
    }

 }
    int numIslands(vector<vector<char>>& grid) {
      int n=grid.size();
      int m=grid[0].size();
      int count=0;
      vector<vector<int>>vis(n,vector<int>(m,0));

      for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(grid[i][j]=='1' && vis[i][j]==0){
                count++;
                vis[i][j]=1;
                dfs(i,j,grid,vis,n,m);

            }
        }
      }
      return count;
    }
};