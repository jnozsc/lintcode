/*
Given an array of integers, the majority number is the number that occurs more than half of the size of the array. Find it.
Example
for [1, 1, 1, 1, 2, 2, 2], return 1
*/
#include <vector>

using namespace std;

class Solution {
  public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        int majority = nums[0];
        int count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == majority) {
                count++;
            } else {
                count--;
            }
            if (count <= 0) {
                majority = nums[i];
                count = 1;
            }
        }
        return majority;
    }
};
