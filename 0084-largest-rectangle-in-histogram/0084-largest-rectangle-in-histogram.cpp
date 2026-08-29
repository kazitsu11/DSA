class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>>st;
        int n=heights.size();
        vector<int>left(n),right(n);

        for(int i=0;i<n;++i){
            while(!st.empty() && heights[i]<=st.top().first){
                st.pop();
            }
            if(st.empty()){
                left[i]=-1;
            }
            else{
                left[i]=st.top().second;
            }
            st.push({heights[i],i});
        }

        while(!st.empty()){
            st.pop();
        }

        for(int i=n-1;i>=0;--i){
            while(!st.empty() && heights[i]<=st.top().first){
                st.pop();
            }
            if(st.empty()){
                right[i]=n;
            }
            else{
                right[i]=st.top().second;
            }
            st.push({heights[i],i});
        }

        int maxarea=0;
        for(int i=0;i<n;++i){
            int width=right[i]-left[i]-1;
            maxarea=max(maxarea,heights[i]*width);
        }
        return maxarea;
    }
};