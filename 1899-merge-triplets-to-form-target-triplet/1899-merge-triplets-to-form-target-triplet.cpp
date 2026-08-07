class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n=triplets.size();
        vector<vector<int>>arr;
        if(n==0) return false;

        for(auto& a:triplets){
            int x=a[0];
            int y=a[1];
            int z=a[2];

            if(x<=target[0] && y<=target[1] && z<=target[2]){
                arr.push_back(a);
            }
        }

        if(arr.size()==0) return false;
         int current_x=arr[0][0];
         int current_y=arr[0][1];
         int current_z=arr[0][2];

         for(int i =0;i<arr.size();++i){
            int next_x=arr[i][0];
            int next_y=arr[i][1];
            int next_z=arr[i][2];

            current_x=max(current_x,next_x);
            current_y=max(current_y,next_y);
            current_z=max(current_z,next_z);

            if(current_x==target[0] && current_y==target[1] && current_z==target[2]) return true;

         }
         return false;
    }
};
