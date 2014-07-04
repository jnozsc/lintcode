/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/
#include <vector>

using namespace std;

class Solution {
    /**
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
  public:
    vector<int> searchRange(vector<int>& A, int target) {
        // write your code here
        vector<int> result(2, -1);
        if (A.empty()) {
            return result;
        }
        if (A.front() == target && A.back() == target) {
            result[0] = 0;
            result[1] = A.size() - 1;
            return result;
        }
        int begin = 0, end = A.size() - 1;
        while (begin + 1 < end) {
            int mid = begin + (end - begin) / 2;
            if (A[mid] == target) {
                return  searchRange(A, target, mid);
            } else if (A[mid] > target) {
                end = mid;
            } else {
                begin = mid;
            }
        }
        if (A[begin] == target) {
            return searchRange(A, target, begin);
        }
        if (A[end] == target) {
            return searchRange(A, target, end);
        }
        return result;
    }
  private:
    vector<int> searchRange(vector<int>& A, int target, int pivot) {
        vector<int> result(2, -1);
        int resultBegin = pivot, resultEnd = pivot;
        while (resultBegin > 0) {
            if (A[resultBegin - 1] == target) {
                resultBegin--;
            } else {
                break;
            }
        }
        while (resultEnd < A.size() - 1) {
            if (A[resultEnd + 1] == target) {
                resultEnd++;
            } else {
                break;
            }
        }
        result[0] = resultBegin;
        result[1] = resultEnd;
        return result;
    }
};
