/*  
    https://leetcode.com/problems/two-sum/description/
    Hash table
    Time complexity - O(n)
    Space complexity - O(n)
*/
class Solution {
    public:
        vector<int> intSum(vector<int>& nums, int target) {
            unordered_map<int,int> hash;
            for(int i = 0; i < nums.size(); i++){
                int complement = target - nums[i];
                if(hash.find(complement) != hash.end()) {
                    return {hash[complement], i};
                }
                hash[nums[i]] = i;
            }
            return {};
        }
};

/*
    Sorting
    Time complexity - O(nlogn)
    Space complexity - O(n)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> v;
        for(int i = 0; i < nums.size(); i++){
            v.push_back({nums[i], i});
        }
        
        sort(v.begin(), v.end());
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            int curr = v[i].first + v[j].first;
            if(curr == target) {
                return  {min(v[i].second, v[j].second),
                        max(v[i].second, v[j].second)};
            } else if (curr < target) {
                i++;
            } else {
                j--;
            }
        }
        return {};
    }
};