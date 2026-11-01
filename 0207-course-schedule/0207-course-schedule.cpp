class Solution {
public:
bool dfs(vector<int>& state,int i,vector<vector<int>>& adj){
    if(state[i]==1) return true;
    if(state[i]==2) return false;

    state[i]=1;

    for(auto& neigh:adj[i]){
        if(dfs(state,neigh,adj)){
            return true;
        }
    }

    state[i]=2;
    return false;
}
    bool canFinish(int numCourses, vector<vector<int>>& prereq) {
      vector<vector<int>>adj(numCourses);
      vector<int>state(numCourses,0);
      for(auto& e:prereq){
        int course=e[0];
        int req=e[1];
        adj[req].push_back(course);
      }

      for(int i=0;i<numCourses;++i){
        if(dfs(state,i,adj)){
            return false;
        }
      }
      return true;
    }
};