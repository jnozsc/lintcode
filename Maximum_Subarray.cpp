/*
Given an array of integers, find a contiguous subarray which has the largest sum.

Note
The subarray should contain at least one number

Example
For example, given the array [−2,2,−3,4,−1,2,1,−5,3], the contiguous subarray [4,−1,2,1] has the largest sum = 6.

Challenge
Can you do it in time complexity O(n)?
*/
#include <vector>

using namespace std;


class Solution {
  public:
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        // write your code here
        if (nums.empty()) {
            return 0;
        }
        int result = nums[0];
        int tmp = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (tmp < 0) {
                tmp = nums[i];
            } else {
                tmp += nums[i];
            }
            result = max(result, tmp);
        }
        return result;
    }
};
