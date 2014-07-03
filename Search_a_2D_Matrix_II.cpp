/*
Write an efficient algorithm that searches for a value in an m x n matrix, return the occurrence of it.

This matrix has the following properties:

    * Integers in each row are sorted from left to right.

    * Integers in each column are sorted from up to bottom.

    * No duplicate integers in each row or column.

Example
Consider the following matrix:

[

    [1, 3, 5, 7],

    [2, 4, 7, 8],

    [3, 5, 9, 10]

]

Given target = 3, return 2.

Challenge Expand
O(m+n) time and O(1) extra space
*/
#include <vector>

using namespace std;

class Solution {
  public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int> >& matrix, int target) {
        // write your code here
        int result = 0;
        int rows = matrix.size();
        if (rows == 0) {
            return result;
        }
        int columns = matrix[0].size();
        if (columns == 0) {
            return result;
        }
        int i = 0, j = columns - 1;
        while (i < rows && j >= 0) {
            if (matrix[i][j] == target) {
                result++;
                i++;
            } else if (matrix[i][j] > target) {
                j--;
            } else {
                i++;
            }
        }
        return result;
    }
};
