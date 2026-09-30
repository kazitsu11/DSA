class Solution {
public:
vector<vector<int>>directions={{-1,0},{1,0},{0,-1},{0,1}};
void dfs(vector<vector<int>>& heights,int i,int j, vector<vector<bool>>&vis){
    int n=heights.size();
    int m=heights[0].size();
    
    vis[i][j]=true;

    for(auto& dir:directions){
        int new_i=i+dir[0];
        int new_j=j+dir[1];

        if(new_i>=0 && new_j>=0 && new_i<n && new_j<m && heights[new_i][new_j]>=heights[i][j] && !vis[new_i][new_j]){
           vis[new_i][new_j]=true;
           dfs(heights,new_i,new_j,vis);
        }
    }
}
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>ans;
        vector<vector<bool>>pacific(n,vector<bool>(m,false));
        vector<vector<bool>>atlantic(n,vector<bool>(m,false));


        for(int j=0;j<m;++j){
            dfs(heights,0,j,pacific);
            dfs(heights,n-1,j,atlantic);
        }

        for(int i=0;i<n;++i){
            dfs(heights,i,0,pacific);
            dfs(heights,i,m-1,atlantic);
        }

        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};