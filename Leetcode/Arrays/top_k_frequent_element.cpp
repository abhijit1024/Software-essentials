/*
    https://leetcode.com/problems/top-k-frequent-elements/description/
    Time complexity - O(nlogn)
    Space complexity - O(n)
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for(int num: nums) {
            map[num]++;
        }
        vector<pair<int, int>> v;
        for(pair<int, int> p: map) {
            v.push_back(p);
        }
        sort(v.begin(), v.end(),[](pair<int, int> a, pair<int, int> b){
            return a.second > b.second;
        });
        vector<int> res;
        for(int i = 0; i < k; i++){
            res.push_back(v[i].first);
        }
        return res;
    }
};

/*

*/
class Solution {
public:

};