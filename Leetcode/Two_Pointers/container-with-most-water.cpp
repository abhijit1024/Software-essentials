/*
    https://leetcode.com/problems/container-with-most-water/description/
    Time complexity - O(n)
    Space complexity - O(1)
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int res = 0;
        while (left < right) {
            int area = min(height[left], height[right]) * (right - left);
            res = max(res, area);
            if(height[left] > height[right]) {
                right --;
            } else {
                left ++;
            }
        }
        return res;
    }
};