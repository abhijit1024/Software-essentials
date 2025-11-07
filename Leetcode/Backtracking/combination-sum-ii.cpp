/*
    https://leetcode.com/problems/combination-sum-ii/description/
    Tc -
    Sc - 
*/
class Solution {
public:
    void findCombination(int curr, int target, vector<int>& arr, vector<vector<int>>& ans,
                            vector<int>& subset) {
        if(target == 0) {
            ans.push_back(subset);
            return;
        }
        if(curr == arr.size())
            return;
        for(int i = curr; i < arr.size(); i++) {
            //check duplicate candidates
            if(i == curr || arr[i] != arr[i - 1]) {
                if(arr[i] > target) break;
                subset.push_back(arr[i]);
                //check next index 
                findCombination(i + 1, target - arr[i], arr, ans, subset);
                subset.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> subset;
        //sorting helps to detect duplicate candidates
        sort(candidates.begin(), candidates.end());
        findCombination(0, target, candidates, ans, subset);
        return ans;
    }
};