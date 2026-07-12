class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
       unordered_map<int,int>mp;
       vector<int>arr2;
       vector<int>res;
       int n=arr.size();
       for(int i=0;i<n;i++){
      arr2.push_back(arr[i]);
       }

       sort(arr2.begin(),arr2.end());
       int rank=1;
       for(int i=0;i<n;++i){
        if(i>0 && arr2[i]==arr2[i-1]){
            mp[arr2[i]]=mp[arr2[i-1]];
        }
        else{
        mp[arr2[i]]=rank;
        rank++;
        }
       }

       for(auto & e:arr){
        res.push_back(mp[e]);
       }
       return res;
    }
};