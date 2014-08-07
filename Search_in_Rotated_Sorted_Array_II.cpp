/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
*/
#include <vector>

using namespace std;

class Solution {
    /**
     * param A : an integer ratated sorted array and duplicates are allowed
     * param target :  an integer to be search
     * return : a boolean
     */
  public:
    bool search(vector<int>& A, int target) {
        // write your code here
        return searchRecursion(A, 0, A.size() - 1, target);
    }

    bool searchRecursion(vector<int>& A, int begin, int end, int target) {
        if (begin > end) {
            return false;
        }
        if (begin == end) {
            return A[begin] == target;
        }
        int mid = begin + (end - begin) / 2;
        if (A[mid] == target) return true;
        if (A[begin] < A[mid] && begin != mid) {
            if (A[begin] <= target && target <= A[mid]) {
                return searchRecursion(A, begin, mid - 1, target);
            } else {
                return searchRecursion(A, mid + 1, end, target);
            }
        } else if (A[mid] < A[end]) {
            if (A[mid] <= target && target <= A[end]) {
                return searchRecursion(A, mid + 1, end, target);
            } else {
                return searchRecursion(A, begin, mid - 1, target);
            }
        } else {
            return searchRecursion(A, begin, mid - 1, target) || searchRecursion(A, mid + 1, end, target);
        }
    }
};
