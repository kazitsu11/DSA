class Solution {
public:
    vector<string> createGrid(int n, int m) {
        vector<string>grid(n,string(m-1,'#')+".");
        grid[0]=string(m,'.');
        return grid;
    }
};