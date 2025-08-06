/*
    https://leetcode.com/problems/majority-element/description/
    Time complexity - O(n)
    Space complexity - O(1)
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0, count = 0;
        for(int num: nums) {
            if(count == 0) {
                res = num;
            }
            if(num == res) {
                count++;
            } else {
                count--;
            }
        }
        return res;
    }
};