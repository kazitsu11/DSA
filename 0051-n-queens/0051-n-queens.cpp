class Solution {
public:
void solve(int row,int n,vector<string>&board,vector<vector<string>>&res,unordered_set<int>&cols,unordered_set<int>&diag1,unordered_set<int>&diag2){
    if(row==n){
        res.push_back(board);
        return;
    }

    for(int col=0;col<n;++col){
        int d1=row-col;
        int d2=row+col;

        if(cols.count(col) || diag1.count(d1) || diag2.count(d2)) continue;

        board[row][col]='Q';
        cols.insert(col);
        diag1.insert(d1);
        diag2.insert(d2);

        solve(row+1,n,board,res,cols,diag1,diag2);
        board[row][col]='.';
        cols.erase(col);
        diag1.erase(d1);
        diag2.erase(d2);
    }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        vector<vector<string>>res;
        unordered_set<int>cols,diag1,diag2;
        solve(0,n,board,res,cols,diag1,diag2);
        return res;
    }
};