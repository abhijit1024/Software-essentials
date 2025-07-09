// Sorting 
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;

        sort(nums.begin(), nums.end());

        int max_count = 1, curr_max = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i]  == nums[i-1]+1){
                curr_max++;
            }
            else if (nums[i] != nums[i - 1]) {
                max_count = max(max_count, curr_max);
                curr_max = 1;
            }
            
        }
        return max_count = max(max_count, curr_max);
    }
};
