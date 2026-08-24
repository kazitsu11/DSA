class Solution {
public:
bool solve(vector<vector<char>>& board, string &word,int r,int c,int idx){
    if(idx==word.size()) return true;
    if(r<0 || c<0 || r>=board.size() || c>=board[0].size() || board[r][c]!=word[idx]) return false;

    char temp=board[r][c];
    board[r][c]='#';

    bool found= solve(board,word,r-1,c,idx+1)||
                solve(board,word,r+1,c,idx+1)||
                solve(board,word,r,c-1,idx+1)||
                solve(board,word,r,c+1,idx+1);

    board[r][c]=temp;

    return found;
}
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();

        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(solve(board,word,i,j,0)) return true;
            }
        }
        return false;
    }
};