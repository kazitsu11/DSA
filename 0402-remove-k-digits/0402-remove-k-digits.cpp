class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        int n=num.size();
        string ans;
        for(int i=0;i<n;++i){
            while(!st.empty() && num[i]<st.top() && k>0){
                st.pop();
                k--;
            }
            
            st.push(num[i]);
        }

        while(k>0 && !st.empty()){
           st.pop();
           k--;
        }

        while(!st.empty()){
          ans+=st.top();
          st.pop();
        }
        reverse(ans.begin(),ans.end());

int i=0;
        while(ans[i]=='0' && i<ans.size()){
            i++;
        }
          ans= ans.substr(i);

          if(ans.empty()){
            return "0";
          }
           return ans;
    }
};