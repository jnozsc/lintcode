/*
Given 2*n + 1 numbers, every numbers occurs twice except one, find it.

Example
Given [1,2,2,1,3,4,3], return 4

Challenge
One-pass, constant extra space
*/
#include <vector>

using namespace std;

class Solution {
    /**
     *@param A : an integer array
     *return : a integer
     */
  public:
    int singleNumber(vector<int>& A) {
        // write your code here
        if (A.empty()) {
            return 0;
        }
        int result = A[0];
        for (int i = 1; i < A.size(); i++) {
            result ^= A[i];
        }
        return result;
    }
};
