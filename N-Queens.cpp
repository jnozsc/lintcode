/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other. Given an integer n, return all distinct solutions to the n-queens puzzle. Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
Example
There exist two distinct solutions to the 4-queens puzzle:
[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    /**
     * Get all distinct N-Queen solutions
     * @param n: The number of queens
     * @return: All distinct solutions
     * For example, A string '...Q' shows a queen on forth position
     */
    vector<vector<string> > solveNQueens(int n) {
        // write your code here
        vector<vector<string> > allsolutions;
        vector<int> currentSolution;
        solveNQueensDFS(allsolutions, currentSolution, 0, n);
        return allsolutions;
    }

    // convert {1,3,0,2} to [".Q..",  "...Q","Q...","..Q."]
    vector<string> formatSolution(vector<int> solution) {
        vector<string> result(solution.size(), "");
        for (int i = 0; i < solution.size(); i++) {
            for (int j = 0; j < solution[i]; j++) {
                result[i] += ".";
            }
            result[i] += "Q";
            for (int j = solution[i] + 1; j < solution.size(); j++) {
                result[i] += ".";
            }
        }
        return result;
    }

    void solveNQueensDFS(vector<vector<string> >& allsolutions,
                         vector<int>  currentSolution,
                         int currentLevel, int level) {
        // fill in finish, output
        if (currentLevel == level) {
            allsolutions.push_back(formatSolution(currentSolution));
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
