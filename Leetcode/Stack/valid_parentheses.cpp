/*
    https://leetcode.com/problems/valid-parentheses/description/
    Time complexity - O(n)
    Space complexity - O(n)
*/
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> closeToOpen = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        for(char c: s) {
            if(closeToOpen.count(c)) {
                if(!st.empty() && st.top() == closeToOpen[c]) {
                    st.pop();
                } else {
                    return false;
                }
            } else {
                st.push(c);
            }
        }
        return st.empty();
    }
};