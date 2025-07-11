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

/*
    Two pointer
    Time complexity - O(n)
    Space complexity - O(1)
*/
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        while(left < right){
            if(!isalnum(s[left])) {
                left++;
                continue;
            }
            if(!isalnum(s[right])) {
                right--;
                continue;
            }
            if(tolower(s[left]) != tolower(s[right])){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};