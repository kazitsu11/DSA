class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int n = numbers.size();
        int right = n - 1;
        vector<int> arr;
        int sum;
        while (left < right) {
            sum = numbers[left] + numbers[right];
            if (sum == target) {
                arr.push_back(left + 1);
                arr.push_back(right + 1);
                return arr;
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        // arr.push_back(left + 1);
        // arr.push_back(right + 1);
        return arr;
    }
};