/*  
    https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
    Time complexity - O(n)
    Space complexity - O(m)
*/
class Solution {
public:
        int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0;
        vector<int> dict(256, 0);
        int max_len = 0;
        bool repeating = false;
        
        while(i < s.size()) {
            ++dict[s[i]];
            if(dict[s[i]] > 1)
                repeating = true;
            ++i;
           
            while(repeating) {
                --dict[s[j]];
                if(dict[s[j]] >= 1)
                    repeating = false;
                ++j;
            }
            
            max_len = max(max_len, i - j);
        }
        
        return max_len;
    }
};
