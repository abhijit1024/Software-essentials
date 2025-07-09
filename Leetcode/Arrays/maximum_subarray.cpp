// Kadane algorithm
class Solution{
    public:
        int maxSubArray(vector<int>& nums) {
            int curr_sum = 0;
            int max_sum = INT_MIN;
            for(int num: nums){
                curr_sum = max(num,curr_sum + num);
                max_sum = max(max_sum,curr_sum);
            }
            return max_sum;
        }
};