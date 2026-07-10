class Solution {
public:
int rows;
int cols;
int customUp(vector<pair<int,int>>& arr,int target){
    int n=arr.size();
    int l=0;
    int r=n-1;
    int result=0;

    while(l<=r){
        int mid=l+(r-l)/2;
        if(arr[mid].first<=target){
            result=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return result;
}
vector<vector<int>> ancestorTable;
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>> arr(n);

        for(int i=0;i<n;++i){
            arr[i]={nums[i],i};
        }

        sort(arr.begin(),arr.end());

        vector<int>nodetoidx(n);
       for(int i=0;i<n;++i){

        int val=arr[i].first;
        int node=arr[i].second;

        nodetoidx[node]=i;
       }

       rows=n;
       cols=log2(n)+1;
       ancestorTable.resize(rows,vector<int>(cols,-1));

       for(int node=0;node<n;++node){
       int farthestOneHop=customUp(arr,arr[node].first + maxDiff);
        ancestorTable[node][0]=farthestOneHop;

         
       }

       for(int j=1;j<cols;++j){
        for(int node=0;node<n;++node){
            ancestorTable[node][j]=ancestorTable[ancestorTable[node][j-1]][j-1];
        }
       }

       vector<int>res;

       for(auto& q:queries){

        int u=q[0];
        int v=q[1];

        int a=nodetoidx[u];
        int b=nodetoidx[v];
       

       if(a==b){
        res.push_back(0);
        continue;
       }
       if(a>b){
        swap(a,b);
       }
       int curr=a;
       int jumps=0;

       for(int j=cols-1;j>=0;--j){
        if(ancestorTable[curr][j]<b){
            curr=ancestorTable[curr][j];
            jumps+=(1<<j);
        }
       }

       if(ancestorTable[curr][0]>=b){
        res.push_back(jumps+1);
       }
       else
       res.push_back(-1);
       }

       return res;

    }
};