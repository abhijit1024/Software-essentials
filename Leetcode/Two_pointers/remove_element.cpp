/*
    https://leetcode.com/problems/remove-element/
    Time complexity - O(n)
    Space complexity - O(1)
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, n = nums.size();
        while(i < n) {
            if(nums[i] == val) {
                nums[i] = nums[--n];
            } else {
                i++;
            }
        }
        return n;
    }
};