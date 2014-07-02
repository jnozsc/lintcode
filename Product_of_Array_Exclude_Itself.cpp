/*
Given an integers array A.

Define B[i] = A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1], calculate B without divide operation.

Example
For A=[1, 2, 3], B is [6, 3, 2]
*/
#include <vector>

using namespace std;

class Solution {
  public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int>& nums) {
        // write your code here
        if (nums.size() <= 1) {
            vector<long long> result;
            return result;
        }
        vector<long long> left(nums.size(), 1);
        vector<long long> right(nums.size(), 1);
        vector<long long> result(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++) {
            left[i] = left[i - 1] * nums[i - 1];
        }
        for (int i = nums.size() - 2; i >= 0; i--) {
            right[i] =  right[i + 1] * nums[i + 1];
        }
        for (int i = 0; i < left.size(); i++) {
            result[i] = left[i] * right[i];
        }
        return result;
    }
};
