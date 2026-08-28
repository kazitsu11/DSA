class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        vector<vector<double>>fleet;

        vector<int>dist(n);
        for(int i=0;i<n;++i){
            dist[i]=target-position[i];
        }

        for(int i=0;i<n;++i){
            fleet.push_back({(double)position[i],(double)dist[i]/speed[i]});
        }

        sort(fleet.begin(),fleet.end(),[](auto&a,auto&b){
            if(a[0]!=b[0]) return a[0]>b[0];
            return a[1]<b[1];
        });

        double top_time=fleet[0][1];
        int count=1;

        for(int i=1;i<n;++i){
            double curr_time=fleet[i][1];

            if(curr_time<=top_time) continue;
            else{
                count++;
            }
            top_time=curr_time;
        }
   return count;
    }
};