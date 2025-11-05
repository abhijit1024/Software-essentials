/*
    https://leetcode.com/problems/subsets/
    Tc - O(N * 2^N)
    SC - O(N)
*/
class Solution {
public:
    void generateSubset(vector<int>& nums, vector<int>& partial, int i, vector<vector<int>>& result) {
        if(i == nums.size()) {
            result.emplace_back(partial);
            return;
        }
        //include nums[i]
        partial.emplace_back(nums[i]);
        generateSubset(nums, partial, i + 1, result);
        //exclude nums[i]
        partial.pop_back();
        generateSubset(nums, partial, i + 1, result);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> partial;
        generateSubset(nums, partial, 0, result);
        return result;
    }
};