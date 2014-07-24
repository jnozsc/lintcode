/*
Given a rotated sorted array, recover it to sorted array in-place.

Example
[4, 5, 1, 2, 3] -> [1, 2, 3, 4, 5]

Challenge
In-place, O(1) extra space and O(n) time.

Clarification
What is rotated array:

    - For example, the orginal array is [1,2,3,4], The rotated array of it can be [1,2,3,4], [2,3,4,1], [3,4,1,2], [4,1,2,3]
*/
#include <vector>

using namespace std;

class Solution {
  public:
    void recoverRotatedSortedArray(vector<int>& nums) {
        // write your code here
        int rotate = -1;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                rotate = i + 1;
                break;
            }
        }
        if (rotate == -1) {
            return;
        } else {
            int begin, end;
            begin = 0;
            end = rotate - 1;
            while (begin < end) {
                swap(nums[begin++], nums[end--]);
            }
            begin = rotate;
            end = nums.size() - 1;
            while (begin < end) {
                swap(nums[begin++], nums[end--]);
            }
            begin = 0;
            end = nums.size() - 1;
            while (begin < end) {
                swap(nums[begin++], nums[end--]);
            }
        }
    }
};
