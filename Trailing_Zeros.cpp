/*
Write an algorithm which computes the number of trailing zeros in n factorial.
Example
11! = 39916800, so the out should be 2
*/
class Solution {
  public:
    // param n : description of n
    // return: description of return
    long long trailingZeros(long long n) {
        long long divide = 5;
        long long result = 0;
        while (n / divide) {
            result += n / divide;
            divide *= 5;
        }
        return result;
    }
};
