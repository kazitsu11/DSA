class Solution {
public:
    bool isPalindrome(int x) {
        vector<int> arr;
        if (x < 0)return false;

        int temp = x;
        while (temp > 0) {
            int digit = temp % 10;
            arr.push_back(digit);
            temp = temp / 10;
        }

        int left = 0;
        int right = arr.size() - 1;

        while (left <= right) {
            if (arr[left] != arr[right])return false;
            
            left++;
            right--;
        }
        return true;
    }
};