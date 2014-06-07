/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

Note
You may assume that each input would have exactly one solution

Example
numbers=[2, 7, 11, 15], target=9

return [1, 2]
*/
#include <vector>
#include <map>

using namespace std;

class Solution {
  public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1 + 1, index2 + 1] (index1 < index2)
     */
    vector<int> twoSum(vector<int>& nums, int target) {
        // write your code here
        vector<int> result = { -1, -1};
        if (nums.size() < 2) {
            return result;
        }
        map<int, int> myHash;
        for (int i = 0; i < nums.size(); i++) {
            if (myHash.find(target - nums[i]) == myHash.end()) {
                myHash[nums[i]] = i;
            } else {
                result[0] = myHash[target - nums[i]] + 1;
                result[1] = i + 1;
                return result;
            }
        }
        return result;
    }
};
