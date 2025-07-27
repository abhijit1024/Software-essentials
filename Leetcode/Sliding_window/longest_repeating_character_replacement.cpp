/*
    https://leetcode.com/problems/longest-repeating-character-replacement/description/
    Time complexity - O(n)
    Space complexity - O(m)
*/
class Solution {
public:
    int characterReplacement(string s, int k) {
        if(s.empty())
            return 0;
        vector<int> dict(128, 0);
        int flips = k;
        int max_len = 0;
        int max_freq = 0;

        int i = 0, j = 0;
        while(i < s.size()) {
            ++dict[s[i]];
            max_freq = max(max_freq, dict[s[i]]);
            ++i;
            int flips_req = i - j - max_freq;
            while(flips_req > k) {
                --dict[s[j]];
                ++j;
                flips_req = i - j - max_freq;
            }
            max_len = max(max_len, i - j);
        }
        return max_len;
    }
};