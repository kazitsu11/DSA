class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int total=n*m;
        k=k%total;
        vector<vector<int>> ans(n,vector<int>(m));
        vector<int>res;
    
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
         res.push_back(grid[i][j]);
        }
    }

     reverse(res.begin(),res.end());
     reverse(res.begin(),res.begin()+k);
     reverse(res.begin()+k,res.end());

    int idx=0;

     for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            ans[i][j]=res[idx++];
        }
     }
     return ans;
    }
};