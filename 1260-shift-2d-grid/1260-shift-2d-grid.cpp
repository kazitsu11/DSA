class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int total=n*m;
        k=k%total;
        vector<vector<int>> ans(n,vector<int>(m));
    
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
           int curr=i*m+j;
            int next=(curr+k)%total;

           int row=next/m;
           int col=next%m;

            ans[row][col]=grid[i][j];
        }
    }
        return ans;
    }
};