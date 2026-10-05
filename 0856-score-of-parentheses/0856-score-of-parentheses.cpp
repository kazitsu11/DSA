class Solution {
public:
    int scoreOfParentheses(string s) {
          stack<int>st;
          int score=0;
          int n=s.size();
          st.push(0);
          for(int i=0;i<n;++i){
            if(s[i]=='('){
                st.push(0);
            }
            else if(s[i]==')' && st.top()==0){
                st.pop();
                st.top()+=1;
            }
            else if(s[i]==')' && st.top()>0){
             int temp=st.top();
             st.pop();
             st.top()+=2*temp;
            }
          }
          score=st.top();
          return score;
    }
};