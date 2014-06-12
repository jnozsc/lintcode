/*
Given an array of integers and a number k, find k non-overlapping subarrays which have the largest sum.

The number in each subarray should be contiguous.

Return the largest sum.

Note
The subarray should contain at least one number
*/
#include <string>
#include <vector>
#include <climits>

using namespace std;

class Solution {
  public:
    /**
     * @param nums: A list of integers
     * @param k: An integer denote to find k non-overlapping subarrays
     * @return: An integer denote the sum of max k non-overlapping subarrays
     */
    int maxKSubArrays(vector<int> nums, int k) {
        // write your code here
        vector<vector<vector<bool>>> computed(nums.size(), vector<vector<bool>>(nums.size(), vector<bool>(k + 1, false)));
        vector<vector<vector<int>>> subarray(nums.size(), vector<vector<int>>(nums.size(), vector<int>(k + 1, 0)));
        return maxKSubArraysRecursion(nums, 0, nums.size() - 1, k, computed, subarray);
    }

    int maxKSubArraysRecursion(vector<int> nums, int begin, int end, int k, vector<vector<vector<bool>>>& computed, vector<vector<vector<int>>>& subarray) {
        if (computed[begin][end][k] == true) {
            return subarray[begin][end][k];
        } else {
            if (k == 1) {
                subarray[begin][end][k] = max1SubArrarys(nums, begin, end);
                computed[begin][end][k] = true;
                return subarray[begin][end][k];
            } else if (k == 2) {
                subarray[begin][end][k] = max2SubArrarys(nums, begin, end);
                computed[begin][end][k] = true;
                return subarray[begin][end][k];
            } else if (k <= 0 || k > end - begin + 1) {
                subarray[begin][end][k] = INT_MIN;
                computed[begin][end][k] = true;
                return subarray[begin][end][k];
            } else {
                int result = nums[begin] + maxKSubArraysRecursion(nums, begin + 1, end, k - 1, computed, subarray);
                for (int i = 1; i <= end - begin - k + 1; i++) {
                    int left;
                    if (computed[begin][begin + i][1] == true) {
                        left = subarray[begin][begin + i][1];
                    } else {
                        subarray[begin][begin + i][1] = max1SubArrarys(nums, begin, begin + i);
                        computed[begin][begin + i][1] = true;
                        left = subarray[begin][begin + i][1];
                    }
                    result = max(result, left + maxKSubArraysRecursion(nums, begin + i + 1, end, k - 1, computed, subarray));
                }
                subarray[begin][end][k] = result;
                computed[begin][end][k] = true;
                return subarray[begin][end][k];
            }
        }
    }

    int max1SubArrarys(vector<int> nums, int begin, int end) {
        int result = nums[begin];
        int tmp = nums[begin];
        for (int i = begin + 1; i <= end; i++) {
            if (tmp < 0) {
                tmp = nums[i];
            } else {
                tmp += nums[i];
            }
            result = max(result, tmp);
        }
        return result;
    }

    int max2SubArrarys(vector<int> nums, int begin, int end) {
        int maxTo[end - begin + 1];
        int maxFrom[end - begin + 1];
        maxTo[0] = nums[begin];
        int tmp = nums[begin];
        for (int i = begin + 1; i <= end; i++) {
            if (tmp < 0) {
                tmp = nums[i];
            } else {
                tmp += nums[i];
            }
            maxTo[i - begin] = max(tmp, maxTo[i - begin - 1]);
        }
        tmp = nums[end];
        maxFrom[end - begin] = nums[end];
        for (int i = end - 1; i >= begin; i--) {
            if (tmp < 0) {
                tmp = nums[i];
            } else {
                tmp += nums[i];
            }
            maxFrom[i - begin] = max(tmp, maxFrom[i - begin + 1]);
        }
        int result = maxTo[0] + maxFrom[1];
        for (int i = 1; i < end - begin; i++) {
            result = max(result, maxTo[i] + maxFrom[i + 1]);
        }
        return result;
    }
};
