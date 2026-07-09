class Solution {
public:
 int ans=0;
int largestRect(vector<int>& h){
    
          stack<pair<int,int>>st;
          

          for(int i=0;i<=h.size();++i){
             int curr;
             if(i==h.size()){
                curr=0;
             }
             else
             curr=h[i];

             while(!st.empty() && curr<=st.top().first){
                int ht=st.top().first;
                st.pop();

                int width;
                if(st.empty()){
                    width=i;
                }
                else{
                    width=i-st.top().second-1;
                }
                ans=max(ans,ht*width);

             }
             st.push({curr,i});
          }
          return ans;

}
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
         
          vector<int>height(m,0);
        

          for(int i=0;i<n;++i){
               for(int j=0;j<m;++j){
                if(matrix[i][j]=='1'){
                    height[j]++;
                }
                else
                height[j]=0;
               }
               ans=max(ans,largestRect(height));
          }
        

        return ans;
    }
};