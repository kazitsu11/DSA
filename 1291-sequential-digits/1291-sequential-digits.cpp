class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> q;
        vector<int> ans;
        for (int i = 1; i <= 9; ++i) {
            q.push(i);
        }

        while (!q.empty()){
                long long n = q.front();
                q.pop();

                if (n >= low && n <= high) {
                    ans.push_back(n);
                }

                int digit = n % 10;
                if(digit!=9){
                int id = digit + 1;
                n = (1LL *n * 10) + id;
                q.push(n);
                }
               
            }
            return ans;
        }
    };