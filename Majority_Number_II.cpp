/*
Given an array of integers, the majority number is the number that occurs more than 1/3 of the size of the array. Find it.

Note
There is only one majority number in the array
Example
For [1, 2, 1, 2, 1, 3, 3] return 1
*/
#include <vector>

using namespace std;

class Solution {
  public:
    /**
     * @param nums: A list of integers
     * @return: The majority number occurs more than 1/3.
     */
    int majorityNumber(vector<int> nums) {
        // write your cohere
        vector<int> majority;
        vector<int> count;
        majority.push_back(nums[0]);
        count.push_back(1);
        for (int i = 1; i < nums.size(); i++) {
            if (majority.size() == 0
                    || (majority.size() == 1 && nums[i] != majority[0])) {
                majority.push_back(nums[i]);
                count.push_back(1);
            } else if (majority.size() == 1 && nums[i] == majority[0]) {
                count[0]++;
            } else if (majority.size() == 2 && nums[i] == majority[0]) {
                count[0]++;
            } else if (majority.size() == 2 && nums[i] == majority[1]) {
                count[1]++;
            } else {
                count[0]--;
                count[1]--;
            }
            if (count.back() == 0) {
                majority.pop_back();
                count.pop_back();
            }
            if (count.front() == 0) {
                majority.erase(majority.begin());
                count.erase(count.begin());
            }
        }
        if (majority.size() == 1) {
            return majority[0];
        } else {
            return count.front() > count.back() ? majority.front() : majority.back();
        }
    }
};
