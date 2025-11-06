/*
    https://leetcode.com/problems/combination-sum/description/
    TC: O(n ^ (target / min el of candidates)), in each recursive call, n calls are
    made and the depth is equal to max number of elements in the subset that sum to target,
    which is target / min el of candidates
    SC: O(target / min el of candidates), worst case scenario is when the
        smallest element is used to sum upto target. 
        eg target=3, [1,4] => [1,1,1]
*/
class Solution {
public:
    // target - remaining value we still to sum
    // ds - current combination that is built
    // ans - list of valid combination
    // arr - input candidates
    void findCombination(int ind, int target, vector<int>& arr, vector<int>& subset,
                         vector<vector<int>>& ans) {
        
        if(target == 0) {
            ans.push_back(subset); // store current combination
            return;
        } 
        if(ind == arr.size()) return;

        if(arr[ind] <= target) {
            subset.push_back(arr[ind]);
            //Stay at the same index as same element is allowed to reuse
            findCombination(ind, target - arr[ind], arr, subset, ans);
            subset.pop_back(); // undo pick and try next choice
        }
        //skip and check next index
        findCombination(ind + 1, target, arr, subset, ans);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> subset;
        findCombination(0, target, candidates, subset, ans);
        return ans;
    }
};