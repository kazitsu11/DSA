class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        int n=hand.size();
         
         if(n%groupSize!=0) return false;

         map<int,int>mp;

         for(auto& a:hand){
            mp[a]++;
    }

         for(auto& p:mp){
            int card=p.first;
            int freq=p.second;

            for(int i=0;i<groupSize;++i){
                int c=card+i;
                if(freq==0) continue;
                if(mp[c]<freq) return false;
                mp[c]-=freq;
            }
         }
         return true;
    }
};