class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();

        int i=n-1;
        int j=m-1;
        vector<int>rightmatch(n,0);
        int match=0;

        while(i>=0){
            if(j>=0 && word1[i]==word2[j] ){
              match++;
              j--;
            }
            rightmatch[i]=match;
            i--;
        }

         i=0;
         j=0;
        vector<int>ans;
        bool canChange=true;

        while(i<n && j<m){
            if(word1[i]==word2[j]){
               ans.push_back(i);
               j++;
            }
            else if(canChange==true && i+1<n && rightmatch[i+1]>=m-j-1 ){
                ans.push_back(i);
                canChange=false;
                j++;
            }
            ++i;
        }
        if(j==m) return ans;
        return {};
    }
};