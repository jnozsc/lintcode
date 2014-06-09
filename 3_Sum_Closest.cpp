/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers.

Note
You may assume that each input would have exactly one solution.

Example
For example, given array S = {-1 2 1 -4}, and target = 1. The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> nums, int target) {
        // write your code here
        if (nums.size() < 3) {
            return -1;  // error handle
        }
        if (nums.size() == 3) {
            return nums[0] + nums[1] + nums[2];
        }
        sort(nums.begin(), nums.end());
        int result = nums[0] + nums[1] + nums[2];
        for (int i = 0; i <= nums.size() - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int a = nums[i];
            int b_index = i + 1;
            int c_index = nums.size() - 1;
            while (b_index < c_index) {
                if (a + nums[b_index] + nums[c_index] == target) {
                    return target;
                } else if (a + nums[b_index] + nums[c_index] > target) {
                    if (a + nums[b_index] + nums[c_index] - target < abs(result - target)) {
                        result = a + nums[b_index] + nums[c_index];
                    }
                    c_index--;
                } else {
                    if (target - (a + nums[b_index] + nums[c_index]) < abs(result - target)) {
                        result = a + nums[b_index] + nums[c_index];
                    }
                    b_index++;
                }
            }
        }
        return result;
    }
};
