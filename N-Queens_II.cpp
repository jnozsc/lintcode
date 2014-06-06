/*
Follow up for N-Queens problem. Now, instead outputting board configurations, return the total number of distinct solutions.
Example
For n=4, there are 2 distinct solutions.
*/
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    /**
     * Calculate the total number of distinct N-Queen solutions.
     * @param n: The number of queens.
     * @return: The total number of distinct solutions.
     */
    int totalNQueens(int n) {
        // write your code here
        int allsolutions = 0;
        vector<int>  currentSolution;
        solveNQueensDFS(allsolutions, currentSolution, 0, n);
        return allsolutions;
    }

    void solveNQueensDFS(int& allsolutions,
                         vector<int>  currentSolution,
                         int currentLevel, int level) {
        // fill in finish, output
        if (currentLevel == level) {
            allsolutions++;
            return;
        }
        // not finish yet.
        for (int i = 0; i < level; i++) {
            // if it is emtpy or i is in diffent column
            if (currentSolution.empty() || isValid(currentSolution, i)) {
                currentSolution.push_back(i);
                solveNQueensDFS(allsolutions, currentSolution, currentLevel + 1, level);
                currentSolution.pop_back();
            }
        }
    }

    bool isValid(vector<int>  currentSolution, int newPostion) {
        bool flag_column = find(currentSolution.begin(), currentSolution.end(), newPostion) == currentSolution.end();
        if (flag_column == false) {
            return false;
        }
        vector<int> diagonal_one, diagonal_two;
        for (int i = 0; i < currentSolution.size(); i++) {
            diagonal_one.push_back(i + currentSolution[i]);
            diagonal_two.push_back(i - currentSolution[i]);
        }
        bool flag_diagonal_one = find(diagonal_one.begin(), diagonal_one.end(), currentSolution.size() + newPostion) == diagonal_one.end();
        if (flag_diagonal_one == false) {
            return false;
        }
        bool flag_diagonal_two = find(diagonal_two.begin(), diagonal_two.end(), currentSolution.size() - newPostion) == diagonal_two.end();
        if (flag_diagonal_two == false) {
            return false;
        }
        return true;
    }
};
