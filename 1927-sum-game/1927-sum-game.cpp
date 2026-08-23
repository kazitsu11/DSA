class Solution {
public:
    bool sumGame(string num) {
        int n=num.size();
        int leftknownsum=0;
        int rightknownsum=0;

        int leftqnmark=0;
        int rightqnmark=0;

        for(int i=0;i<n;++i){
            if(num[i]=='?'){
                if(i<n/2){
                    leftqnmark++;
                }
                else rightqnmark++;
            }
            else{
                  if(i<n/2){
                    leftknownsum+=num[i]-'0';
                }
                else rightknownsum+=num[i]-'0';

            }
        }

        int total=leftqnmark+rightqnmark;

        if(total%2!=0) return true;

        int left=2*leftknownsum+9*leftqnmark;
        int right=2*rightknownsum+9*rightqnmark;

        if(left==right) return false;
        return true;
    }
};