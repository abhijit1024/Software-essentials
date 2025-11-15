/*
    https://leetcode.com/problems/generate-parentheses/
    Tc - 
    Sc -
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string current;
        backtrack(res, current, 0, 0, n);
        return res;
    }
    void backtrack(vector<string>& res, string& curr, int open, int close, int n) {
        if(curr.size() == 2 * n) {
            res.push_back(curr);
            return;
        }
        if(open < n) {
            curr.push_back('(');
            backtrack(res, curr, open + 1, close, n);
            curr.pop_back();
        }
        if(close < open) {
            curr.push_back(')');
            backtrack(res, curr, open, close + 1, n);
            curr.pop_back();
        }
    }
};