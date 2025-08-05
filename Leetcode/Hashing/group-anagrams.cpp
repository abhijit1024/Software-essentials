/*
    https://leetcode.com/problems/group-anagrams/description/
    Time complexity - O(m*nlogn)
    Space complexity - O(n)
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;
        for(const string& word: strs) {
            string sorted_word = word;
            sort(sorted_word.begin(), sorted_word.end());
            anagrams[sorted_word].emplace_back(word);
        }
        vector<vector<string>> result;
        for(const auto& pair: anagrams) {
            result.push_back(pair.second);
        }
        return result;
    }
};
