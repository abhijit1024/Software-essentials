// Sorting method

class Solution{
    public:
        bool hasDuplicate(vector<int>& nums) {
            sort(nums.begin, nums.end());
            for(int i = 0; i < nums.length()-1; i++) {
                if(nums[i] == nums[i+1]) {
                    return true;
                }
            }
            return false;
        }
};

// Hash table

class Solution{
    public:
        bool hasDuplicate(vector<int>& nums){
            unordered_map<int, int> hash;

            for(int num:nums){
                if(hash[num] > 0){
                    return true;
                }
                hash[num]++;
            }
            return false;
        }
};