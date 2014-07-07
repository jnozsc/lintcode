/*
Given an array of integers and a number k, the majority number is the number that occurs more than 1/k of the size of the array. Find it.

Note
There is only one majority number in the array.

Example
For [3,1,2,3,2,3,3,4,4,4] and k = 3, return 3

Challenge Expand
O(n) time and O(k) extra space
*/
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    /**
     * @param nums: A list of integers
     * @param k: As described
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums, int k) {
        // write your code here

        vector<int> majority;
        vector<int> count;
        for (int i = 0; i < nums.size(); i++) {
            if (find(majority.begin(), majority.end(), nums[i]) == majority.end()) {
                if (majority.size() < k) {
                    majority.push_back(nums[i]);
                    count.push_back(1);
                } else {
                    for (int j = majority.size() - 1; j >= 0; j--) {
                        count[j]--;
                        if (count[j] <= 0) {
                            count.erase(count.begin() + j);
                            majority.erase(majority.begin() + j);
                        }
                    }
                }
            } else {
                count[find(majority.begin(), majority.end(), nums[i]) - majority.begin()]++;
            }
        }
        while (majority.size() > 1) {
            for (int j = majority.size() - 1; j >= 0; j--) {
                count[j]--;
                if (count[j] <= 0) {
                    count.erase(count.begin() + j);
                    majority.erase(majority.begin() + j);
                }
            }
        }
        return majority[0];
    }
};
