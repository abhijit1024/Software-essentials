/*
    https://leetcode.com/problems/valid-palindrome/description/
    Time compelxity - O(n)
    Space complexity - O(n)
*/
class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for(char c: s) {
            if(isalnum(c)) {
                str += tolower(c);
            }
        }
        return str == string(str.rbegin(), str.rend());
    }
};