/*
Given an array of integers, find two non-overlapping subarrays which have the largest sum. The number in each subarray should be contiguous. Return the largest sum.
Example
For given [1, 3, -1, 2, -1, 2],
the two subarrays are [1, 3] and [2, -1, -2] or [1, 3, -1, 2] and [2], they all have the largest sum 7.
*/
#include <vector>

using namespace std;


class Solution {
  public:
    /**
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    int maxTwoSubArrays(vector<int> nums) {
        // write your code here
        int maxTo[nums.size()];
        int maxFrom[nums.size()];
        maxTo[0] = nums[0];
        int tmp = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (tmp < 0) {
                tmp = nums[i];
            } else {
                tmp += nums[i];
            }
            maxTo[i] = max(tmp, maxTo[i - 1]);
        }
        tmp = nums[nums.size() - 1];
        maxFrom[nums.size() - 1] = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (tmp < 0) {
                tmp = nums[i];
            } else {
                tmp += nums[i];
            }
            maxFrom[i] = max(tmp, maxFrom[i + 1]);
        }
        int result = maxTo[0] + maxFrom[1];
        for (int i = 1; i < nums.size() - 1; i++) {
            result = max(result, maxTo[i] + maxFrom[i + 1]);
        }
        return result;
    }
};
