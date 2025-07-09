//kadane algorithm
class Solution{
    public:
        int maxSubArray(vector<int>& nums) {
            int curr_sum = 0;
            int maxSum = nums[0];
            for(int num:nums){
                if(curr_sum < 0){
                    curr_sum = 0;
                }
                curr_sum += num;
                maxSum = max(maxSum,curr_sum);
            }
            return maxSum;
        }
};