class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();

        vector<int>rightMatch(n,0);

        int i=n-1;
        int j=m-1;
        int match=0;

        while(i>=0){
            if(j>=0 && word1[i]==word2[j]){
             match++;
             j--;
            }
            rightMatch[i]=match;
            i--;
        }

        vector<int>seq;
        bool canChange=true;

       i=0;
       j=0;
        while(i<n && j<m){
            if(word1[i]==word2[j]){
                seq.push_back(i);
                j++;
            }
           else if(canChange==true && i+1<n && rightMatch[i+1]>=m-j-1){
                seq.push_back(i);
                canChange=false;
                j++;
            }
            i++;
        }
        if(j==m) return seq;
        return {};
    }
};