class Solution {
public:

vector<vector<int>>directions={{-1,0},{1,0},{0,-1},{0,1}};
void dfs(int i,int j,vector<vector<int>>& image, vector<vector<int>>&vis,int original,int color){
    int n=image.size();
    int m=image[0].size();

   for(auto& dir:directions){
    int new_i=i+dir[0];
    int new_j=j+dir[1];

     if(new_i>=0 & new_j>=0 && new_i<n && new_j<m && image[new_i][new_j]==original && vis[new_i][new_j]==0){
        vis[new_i][new_j]=1;
        image[new_i][new_j]=color;
        dfs(new_i,new_j,image,vis,original,color);
     }
   }
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));

        int original=image[sr][sc];

        if(image[sr][sc]!=color){
            vis[sr][sc]=1;
            image[sr][sc]=color;
            dfs(sr,sc,image,vis,original,color);
        }
        return image;
    }
};