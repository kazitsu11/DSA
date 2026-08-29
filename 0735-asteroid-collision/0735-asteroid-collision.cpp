class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>arr;
        stack<int>st;
     
        for(auto& a:asteroids){
            bool alive=true;
            while(!st.empty() && st.top()>0 && a<0){
              int b=st.top();
              st.pop();
              
              if(b>abs(a)){
                st.push(b);
                alive=false;
                break;
              }
              else if(b==abs(a)){
                alive=false;
                break;
              }
            }
                if(alive) st.push(a);
            }

        if(st.empty()) return {};

        while(!st.empty()){
            arr.push_back(st.top());
            st.pop();
        }
        reverse(arr.begin(),arr.end());
        return arr;
    }
};