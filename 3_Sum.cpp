/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)

The solution set must not contain duplicate triplets.

Example
For example, given array S = {-1 0 1 2 -1 -4}, A solution set is:

(-1, 0, 1)

(-1, -1, 2)
*/
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    /**
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int> > threeSum(vector<int>& nums) {
        // write your code here
        vector<vector<int> > result;
        if (nums.size() < 3) {
            return result;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i <= nums.size() - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int a = nums[i];
            int b_index = i + 1;
            int c_index = nums.size() - 1;
            while (b_index < c_index) {
                if (a + nums[b_index] + nums[c_index] == 0) {
                    vector<int> newSolution = {a, nums[b_index], nums[c_index]};
                    if (find(result.begin(), result.end(), newSolution) == result.end()) {
                        result.push_back(newSolution);
                    }
                    c_index--;
                    b_index++;
                } else if (a + nums[b_index] + nums[c_index] > 0) {
                    c_index--;
                } else {
                    b_index++;
                }
            }
        }
        return result;
    }
};
