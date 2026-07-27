class Solution {
public:
bool isPal(string &s,int i,int j){
    if(i>=j){
        return true;
    }
    if(s[i]==s[j]){
        return isPal(s,i+1,j-1);
    }
    return false;
}
    int countSubstrings(string s) {
        int n=s.length();
        int count=0;
        for(int i=0;i<n;++i){
            for(int j=i;j<n;++j){
                if(isPal(s,i,j)){
                 count++;
                }
            }
        }
        return count;
    }
};
