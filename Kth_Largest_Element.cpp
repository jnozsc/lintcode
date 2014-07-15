/*
Find K-th largest element in an array.
Note
You can swap elements in the array
Example
In array [9,3,2,4,8], the 3th largest element is 4
*/
#include<vector>
#include <stdlib.h>

using namespace std;
class Solution {
  public:
    //param k : description of k
    //param a : description of array and index 0 ~ n-1
    //return: description of return
    int kthLargestElement(int k, vector<int> a) {
        return kthLargestElement(k, a, 0, a.size() - 1);
    }

    int kthLargestElement(int k, vector<int>& a, int begin, int end) {
        if (begin == end) {
            return a[begin];
        }
        int q = pivot(a, begin, end);
        if (q + 1 == k) {
            return a[q];
        } else if (q + 1 > k) {
            kthLargestElement(k, a, begin, q - 1);
        } else {
            kthLargestElement(k, a, q + 1, end);
        }
    }

    int pivot(vector<int>& a, int begin, int end) {
        int pivotIndex = begin + (rand() % (end - begin + 1));
        int pivot = a[pivotIndex];
        swap(a[pivotIndex], a[begin]);
        int i = begin, j, temp;
        for (j = begin + 1; j <= end; j++) {
            if (a[j] > pivot) {
                i++;
                swap(a[i], a[j]);
            }
        }
        swap(a[i], a[begin]);
        return i;
    }
};
