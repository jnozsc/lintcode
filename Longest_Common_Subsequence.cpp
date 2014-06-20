/*
Given two strings, find the longest comment subsequence (LCS).

Your code should return the length of LCS.

Example
For "ABCD" and "EDCA", the LCS is "A" (or D or C), return 1

For "ABCD" and "EACB", the LCS is "AC", return 2
*/
#include <string>

using namespace std;

class Solution {
  public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */

    /*    first, think as recursion

    int longestCommonSubsequence(string A, string B) {
        // write your code here
        if (A.empty() || B.empty()) {
            return 0;
        } else if (A[A.length() - 1] == B[B.length() - 1]) {
            return 1 + longestCommonSubsequence(A.substr(0, A.length() - 1), B.substr(0, B.length() - 1));
        } else {
            return max(longestCommonSubsequence(A.substr(0, A.length() - 1), B), longestCommonSubsequence(A, B.substr(0, B.length() - 1)));
        }
    }

    ok, now convert it to dp
    */
    int longestCommonSubsequence(string A, string B) {
        // write your code here
        int m = A.length();
        int n = B.length();
        int dp[m + 1][n + 1];
        int i, j;

        for (i = 0; i <= m; i++) {
            for (j = 0; j <= n; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                }  else if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};


