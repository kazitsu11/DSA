class Solution {
public:
    string smallestSubsequence(string s) {
        stack<char>st;
        unordered_map<char,int>mp;
        string s1;
        for(auto & a:s){
            mp[a]++;
        }
        vector<bool>vis(26,false);

        for(auto & a:s){
            mp[a]--;

            if(vis[a-'a']==true){
                continue;
            }

            while(!st.empty() && a<=st.top() && mp[st.top()]>0){
                vis[st.top()-'a']=false;
                st.pop();
            }
            st.push(a);
            vis[a-'a']=true;
        }
    while(!st.empty()){
        s1.push_back(st.top());
        st.pop();
    }
    reverse(s1.begin(),s1.end());
    return s1;
    }
};