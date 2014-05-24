/*
Binary search is a famous question in algorithm. For a given sorted array (ascending order) and a target number, find the first index of this number in O(log n) time complexity. If the target number does not exist in the array, return -1.
Example
If the array is [1, 2, 3, 3, 4, 5, 10], for given target 3, return 2.
*/
#include <vector>
using namespace std;

class Solution {
  public:
    /**
     * @param array source array
     * @param target target to search
     * @return the first occurrence position of target
     */
    int binarySearch(vector<int>& array, int target) {
        // write your code here
        if (array.empty()) {
            return -1;
        }
        int begin = 0;
        int end = array.size() - 1;
        while (begin < end) {
            int mid = begin + (end - begin) / 2;
            if (array[mid] == target) {
                while (mid >= 0 && array[mid] == target) {
                    mid--;
                }
                return mid + 1;
            } else if (array[mid] > target) {
                end = mid - 1;
            } else {
                begin = mid + 1;
            }
        }
        if (array[end] == target) {
            return end;
        }
        if (array[begin] == target) {
            return begin;
        }
        return -1;
    }
};
