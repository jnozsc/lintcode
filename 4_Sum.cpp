/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)

The solution set must not contain duplicate quadruplets.

Example
For example, given array S = {1 0 -1 0 -2 2}, and target = 0. A solution set is:

(-1, 0, 0, 1)

(-2, -1, 1, 2)

(-2, 0, 0, 2)
*/
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    /**
     * @param numbers: Give an array numbersbers of n integer
     * @param target: you need to find four elements that's sum of target
     * @return: Find all unique quadruplets in the array which gives the sum of zero.
     */
    vector<vector<int> > fourSum(vector<int> nums, int target) {
        // write your code here
        vector<vector<int> > result;
        if (nums.size() < 4) {
            return result;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i <= nums.size() - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int a = nums[i];
            for (int j = i + 1; j <= nums.size() - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int b = nums[j];
                int c_index = j + 1;
                int d_index = nums.size() - 1;
                while (c_index < d_index) {
                    if (a + b + nums[c_index] + nums[d_index] == target) {
                        vector<int> newSolution = {a, b, nums[c_index], nums[d_index]};
                        if (find(result.begin(), result.end(), newSolution) == result.end()) {
                            result.push_back(newSolution);
                        }
                        c_index++;
                        d_index--;
                    } else if (a + b + nums[c_index] + nums[d_index] > target) {
                        d_index--;
                    } else {
                        c_index++;
                    }
                }
            }
        }
        return result;
    }
};
