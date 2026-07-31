class Solution {
public: 
int dp[201][201];
vector<vector<int>>directions={{-1,0},{1,0},{0,-1},{0,1}};
int dfs(int i,int j,vector<vector<int>>&matrix){

int n=matrix.size();
int m=matrix[0].size();
int path=1;

if(dp[i][j]!=-1)  return dp[i][j];

    for(auto& dir:directions){
        int new_i=i+dir[0];
        int new_j=j+dir[1];

        if(new_i>=0 && new_j>=0 && new_i<n && new_j<m && matrix[new_i][new_j]> matrix[i][j]){
          path=max(path,1+dfs(new_i,new_j,matrix));
        }
    }
    return dp[i][j]=path;

}
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=INT_MIN;
        memset(dp,-1,sizeof(dp));
     

        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
              ans=max(ans,dfs(i,j,matrix)); 
            }
        }
        return ans;
    }
};
