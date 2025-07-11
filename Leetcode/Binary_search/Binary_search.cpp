/*
    https://leetcode.com/problems/binary-search/description/
    Time complexity- O(logn)
    Space complexity- O(1)
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left <= right) {
            int mid = (left + right) / 2;
            if(nums[mid] < target) {
                left = mid + 1 ;
            } else if(nums[mid] > target) {
                right = mid - 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};