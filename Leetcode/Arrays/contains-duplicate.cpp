/*
    https://leetcode.com/problems/contains-duplicate/description/
    Time complexity - O(nlogn)
    Space complexity - O(1)
*/

class Solution{
    public:
        bool hasDuplicate(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            for(int i = 0; i < nums.length()-1; i++) {
                if(nums[i] == nums[i+1]) {
                    return true;
                }
            }
            return false;
        }
};

/*  
    Hash table
    Time complexity - O(n)
    Space complexity - O(n)
*/

class Solution{
    public:
        bool hasDuplicate(vector<int>& nums) {
            unordered_map<int, int> hash;

            for(int num: nums){
                if(hash[num] > 0) {
                    return true;
                }
                hash[num]++;
            }
            return false;
        }
};

/*
    Hash set
    Time complexity - O(n)
    Space complexity - O(n)
 */

class Solution{
    public:
        bool hasDuplicate(vector<int>& nums) {
            set<int> seen;

            for(int num: nums){
                if(seen.count(num)) {
                    return true;
                }
                seen.insert(num);
            }
            return false;
        }
};