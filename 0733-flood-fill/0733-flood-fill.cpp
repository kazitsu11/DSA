class Solution {
public:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {

        int n = image.size();
        int m = image[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>>vis(n,vector<int>(m,0));

        int initial_color=image[sr][sc];
        if(initial_color==color){
            return image;
        }
        
        q.push({sr,sc});
        vis[sr][sc]=1;
        image[sr][sc]=color;

        while(!q.empty()){
            int u = q.front().first;
            int v = q.front().second;
            q.pop();

            for (auto& dir : directions) {
                int new_i = u + dir[0];
                int new_j = v + dir[1];

                if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && vis[new_i][new_j] == 0 && image[new_i][new_j] == initial_color) {
                    image[new_i][new_j] = color;
                     q.push({new_i, new_j});
                }
            }   
        }
        return image;
    }
};