/*
Count the number of k's between 0 and n. k can be 0 - 9.
Example
if n=12, in [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12], we have FIVE 1's (1, 10, 11, 12)
*/
class Solution {
    // param k : description of k
    // param n : description of n
    // return ans a integer
  public:
    int digitCounts(int k, int n) {
        int result = 0;
        for (int i = 0; i <= n; i++) {
            int old_i = i;
            while (i) {
                if (i % 10 == k) {
                    result++;
                }
                i = i / 10;
            }
            i = old_i;
        }
        return result;
    }
};
