class Solution {
public:
vector<vector<int>>directions={{-1,0},{1,0},{0,-1},{0,1}};
void dfs(int i,int j,vector<vector<char>>& board){
    int n=board.size();
    int m=board[0].size();

    if(board[i][j]!='O') return;

    board[i][j]='T';

    for(auto& dir:directions){
     int new_i=i+dir[0];
     int new_j=j+dir[1];

     if(new_i>=0 && new_j>=0 && new_i<n && new_j<m){
        dfs(new_i,new_j,board);
     }
    }
}
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

        for(int i=0;i<n;++i){
            dfs(i,0,board);
            dfs(i,m-1,board);
        }

        for(int j=0;j<m;++j){
            dfs(0,j,board);
            dfs(n-1,j,board);
        }

        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(board[i][j]=='O') board[i][j]='X';
                else if(board[i][j]=='T') board[i][j]='O';
            }
        }
    }
};