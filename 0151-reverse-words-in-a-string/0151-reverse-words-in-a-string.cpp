class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int left = 0;
        int right = n - 1;

        while(left<=right && s[left]==' ') left++;

        while(left<=right && s[right]==' ') right--;

        string t;

        while(left<=right){
        if(s[left]==' ' && left>0 && s[left-1]==' '){
            left++;
            continue;
        }
         t+=s[left];
         left++;
        }

        reverse(t.begin(), t.end());

        int end;
        int start = 0;
        int m=t.size();
        for (int i = 0; i < m; ++i) {
            if (t[i] == ' ') {
                end = i;
                reverse(t.begin() + start, t.begin() + end);
                start = end+1;
            }
        }
        reverse(t.begin()+start,t.end());
        return t;
    }
};