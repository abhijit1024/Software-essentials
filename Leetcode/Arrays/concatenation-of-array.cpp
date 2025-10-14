/*
    https://leetcode.com/problems/concatenation-of-array/description/
    Time complexity - O(n)
    Space complexity - O(n)
*/
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2*n);
        for(int i = 0; i < n; i++) {
            ans[i] = ans[i + n] = nums[i];
        }
        return ans;
    }
};