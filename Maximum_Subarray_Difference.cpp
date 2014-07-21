/*
Given an array with integers. Find two non-overlapping subarrays A and B, which |SUM(A) - SUM(B)| is the largest. Return the largest difference.
Example
for [1, 2, -3, 1], return 6
*/
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
  public:
    /**
     * @param nums: A list of integers
     * @return: An integer indicate the value of maximum difference between two
     *          Subarrays
     */
    int maxDiffSubArrays(vector<int> nums) {
        // write your code here
        int tmpMin, tmpMax;
        int maxTo[nums.size()];
        int maxFrom[nums.size()];
        int minTo[nums.size()];
        int minFrom[nums.size()];
        maxTo[0] = nums[0];
        minTo[0] = nums[0];
        tmpMin = nums[0];
        tmpMax = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (tmpMax < 0) {
                tmpMax = nums[i];
            } else {
                tmpMax += nums[i];
            }
            maxTo[i] = max(tmpMax, maxTo[i - 1]);
            if (tmpMin >= 0) {
                tmpMin = nums[i];
            } else {
                tmpMin += nums[i];
            }
            minTo[i] = min(tmpMin, minTo[i - 1]);
        }
        tmpMin = nums[nums.size() - 1];
        tmpMax = nums[nums.size() - 1];
        minFrom[nums.size() - 1] = nums[nums.size() - 1];
        maxFrom[nums.size() - 1] = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (tmpMax < 0) {
                tmpMax = nums[i];
            } else {
                tmpMax += nums[i];
            }
            maxFrom[i] = max(tmpMax, maxFrom[i + 1]);
            if (tmpMin >= 0) {
                tmpMin = nums[i];
            } else {
                tmpMin += nums[i];
            }
            minFrom[i] = min(tmpMin, minFrom[i + 1]);
        }
        int result = max(maxTo[0] - minFrom[1],  maxFrom[1] - minTo[0]);
        for (int i = 1; i < nums.size() - 1; i++) {
            result = max(result, max(maxTo[i] - minFrom[i + 1], maxFrom[i + 1] - minTo[i]));
        }
        return result;
    }
};