class Solution {
public:
    long long iscount(long long mid, vector<int>& coins) {
        long long count = 0;
        int n=coins.size();

        for (int mask = 1; mask < (1 << n); mask++) {
            long long lcm = 1;
            int cnt = 0;

            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    cnt++;
                    lcm = lcm / gcd(lcm, (long long)coins[i]) * coins[i];

                    if (lcm > mid)
                        break;
                }
            }
            if (lcm > mid)
                continue;
            if (cnt % 2 == 1)
                count += mid / lcm;
            else
                count -= mid / lcm;
        }
        return count;
} 
long long findKthSmallest(vector<int>& coins, int k) {

    int n = coins.size();

    long long low = *min_element(coins.begin(), coins.end());

    long long high = 1LL**max_element(coins.begin(), coins.end()) * k;
    long long ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (iscount(mid, coins) >= k) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}
}
;