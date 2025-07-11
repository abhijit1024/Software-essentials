/*
    https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
    Time complexity - O(n)
    Space complexity - O(1)
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            int curr_sum = numbers[left] + numbers[right];
            if( curr_sum > target) {
                right --;
            } else if (curr_sum < target) {
                left ++;
            } else {
                return {left, right};
            }
        }
        return {};
    }
};