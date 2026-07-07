class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int>pq;
        int n=capital.size();
        vector<vector<int>>projects;
        for(int i=0;i<n;++i){
         projects.push_back({capital[i],profits[i]});
        }
        sort(projects.begin(),projects.end());
        int i=0;

        while(k>0){
             while(i<n && w>=projects[i][0]){
                pq.push(projects[i][1]);
                i++;
             }
             if(pq.empty()){
                break;
             }
             w+=pq.top();
             pq.pop();
             k--;
        }
        return w;
        }
};