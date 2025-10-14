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
/*
    Time complexity - O(n)
    Space compleixty - O(n)
*/
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i < 2; i++) {
            for(int num: nums) {
                ans.push_back(num);
            }
        }
        return ans;
    }
};