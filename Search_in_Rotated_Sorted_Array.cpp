/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Example
For [4, 5, 1, 2, 3] and target=1, return 2

For [4, 5,1, 2, 3] and target=0, return -1
*/
#include <vector>

using namespace std;

class Solution {
    /**
     * param A : an integer ratated sorted array
     * param target :  an integer to be searched
     * return : an integer
     */
  public:
    int search(vector<int>& A, int target) {
        // write your code here
        if (A.empty()) {
            return -1;
        }
        if (A.size() == 1) {
            return A[0] == target ? 0 : -1;
        }
        int begin = 0, end = A.size() - 1;
        while (begin + 1 < end) {
            int mid = begin + (end - begin) / 2;
            if (A[mid] == target) {
                return mid;
            } else if (A[begin] < A[mid]) {
                if (A[begin] <= target && target <= A[mid]) {
                    end = mid;
                } else {
                    begin = mid;
                }
            } else if (A[mid] < A[end]) {
                if (A[mid] <= target && target <= A[end]) {
                    begin = mid;
                } else {
                    end = mid;
                }
            } else {
                begin = mid;
            }
        }
        if (A[end] == target) {
            return end;
        }
        if (A[begin] == target) {
            return begin;
        }
        return -1;
    }
};
