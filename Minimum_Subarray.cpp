/*
Given an array of integers, find the subarray with smallest sum. Return the sum of the subarray.
Note
The subarray should have at least one integer.
Example
for [1, -1, -2, 1], return -3
*/
#include <vector>

using namespace std;

class Solution {
  public:
    /**
     * @param nums: a list of integers
     * @return: A integer denote the sum of minimum subarray
     */
    int minSubArray(vector<int> nums) {
        // write your code here
        int result = nums[0];
        int tmp = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (tmp > 0) {
                tmp = nums[i];
            } else {
                tmp += nums[i];
            }
            result = min(result, tmp);
        }
        return result;
    }
};
