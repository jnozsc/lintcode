/*
Given three strings: s1, s2, s3, determine whether s3 is formed by the interleaving of s1 and s2.
Example
s1 = "aabcc"
s2 = "dbbca"

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
*/
#include <vector>
#include <string>

using namespace std;


class Solution {
  public:
    /**
     * Determine whether s3 is formed by interleaving of s1 and s2.
     * @param s1, s2, s3: As description.
     * @return: true of false.
     */
    bool isInterleave(string s1, string s2, string s3) {
        // write your code here
        int n1 = s1.size();
        int n2 = s2.size();
        vector<vector<bool> > A(n1 + 1, vector<bool>(n2 + 1, false));
        if (n1 + n2 != s3.size()) {
            return false;
        }
        if (s1.empty() && s2.empty() && s3.empty()) {
            return true;
        }

        A[0][0] = true;
        for (int i = 1; i <= n1; i++) {
            if (s1[i - 1] == s3[i - 1] && A[i - 1][0]) {
                A[i][0] = true;
            }
        }
        for (int i = 1; i <= n2; i++) {
            if (s2[i - 1] == s3[i - 1] && A[0][i - 1]) {
                A[0][i] = true;
            }
        }

        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                A[i][j] = (A[i][j - 1] && (s2[j - 1] == s3[i + j - 1]))
                          || (A[i - 1][j] && (s1[i - 1] == s3[i + j - 1]));
            }
        }
        return A[n1][n2];
    }
};
