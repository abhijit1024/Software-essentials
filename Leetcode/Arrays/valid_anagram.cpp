/*
    https://leetcode.com/problems/valid-anagram/description/
    Time complexity - O(m+n)
    Space complexity - O(1)
*/
class Solution{
    public:
        bool isAnagram(string s, string t) {
            if(s.length() != t.length()) {
                return false;
            }
            unordered_map<int, int> countS;
            unordered_map<int, int> countT;
            for(int i = 0; i < s.length(); i++) {
                countS[s[i]]++;
                countT[t[i]]++;
            }
            return counts == countT;
        }
};

/*
    Hash set
    Time complexity - O(n+m)
    Space complexity - O(n+m)
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;

        unordered_map<int, int> count;
        
        for(char c: s){
            count[c]++;
        }
        for(char c: t){
            if(count.find(c) == count.end() || count[c] == 0){
                return false;
            }
            count[c]--;
        }
        return true;
    }
};
