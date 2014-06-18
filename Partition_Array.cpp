/*
Given an array "nums" of integers and an int "k", Partition the array (i.e move the elements in "nums") such that, - All elements < k are moved to the left - All elements >= k are moved to the right Return the partitioning Index, i.e the first index "i" nums[i] >= k.
Note
You should do really partition in array "nums" instead of just counting the numbers of integers smaller than k.
If all elements in "nums" are <k, then clearly "i" cannot be a valid index in "nums" (as per the above requirement).
So in such a case, return (<lastIndex in "nums"> + 1) i.e "nums.length"
Example
If nums=[3,2,2,1] and k=2, a valid answer is 1.
*/
#include <vector>

using namespace std;

class Solution {
  public:
    int partitionArray(vector<int>& nums, int k) {
        // write your code here
        if (nums.empty()) {
            return 0;
        }
        int less = 0, equal = 0, larger = nums.size() - 1;
        while (equal <= larger) {
            if (nums[equal] < k) {
                swap(nums[less++], nums[equal++]);
            } else if (nums[equal] == k) {
                equal++;
            } else {
                swap(nums[equal], nums[larger--]);
            }
        }
        return less;
    }
};
