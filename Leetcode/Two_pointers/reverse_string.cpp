/*
    https://leetcode.com/problems/reverse-string/description/
    Two pointer swap
    Time complexity - O(n)
    Space complexity - O(1)
*/
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            swap(s[left++], s[right--]);
        }
    }
};
