/*
Design an algorithm to find the kth number such that the only prime factors are 3, 5, and 7. The eligible numbers are like 3, 5, 7, 9, 15 ...
Example
If k=4, return 9.
*/
// in fact, its name is ugly number.
// time O(n)
// min is in algorithm lib and use std::
// use long long
#include <algorithm>
using namespace std;

class Solution {
  public:
    /*
     * @param k: The number k.
     * @return: The kth prime number as description.
     */
    long long kthPrimeNumber(int k) {
        // write your code here
        long long dp[k + 1];
        dp[0] = 1;
        int three = 0, five = 0, seven = 0;
        for (int i = 1; i <= k; i++) {
            long long next = min(min(dp[three] * 3, dp[five] * 5), dp[seven] * 7);
            dp[i] = next;
            if (next == dp[three] * 3) {
                three++;
            }
            if (next == dp[five] * 5) {
                five++;
            }
            if (next == dp[seven] * 7) {
                seven++;
            }
        }
        return dp[k];
    }
};
