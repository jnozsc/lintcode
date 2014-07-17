/*
Given a list of integers, which denote a permutation.

Find the previous permutation in ascending order.

Note
The list may contains duplicate integers.

Example
For [1,3,2,3], the previous permutation is [1,2,3,3]

For [1,2,3,4], the previous permutation is [4,3,2,1]
*/
#include <vector>

using namespace std;

class Solution {
  public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's previous permuation
     */
    vector<int> previousPermuation(vector<int>& nums) {
        // write your code here
        int index = nums.size() - 1;
        while (index > 0) {
            if (nums[index - 1] > nums[index]) {
                break;
            }
            index--;
        }
        if (index > 0) {
            int i = index - 1;
            int j = nums.size() - 1;
            while (j > i) {
                if (nums[j] < nums[i]) {
                    break;
                }
                j--;
            }
            swap(nums[i], nums[j]);
        }
        int begin = index;
        int end = nums.size() - 1;
        while (begin < end) {
            swap(nums[begin], nums[end]);
            begin++;
            end--;
        }
        return nums;
    }
};
