/*
Given number n. Print number from 1 to n. but when number is divided by 3, print fizz; when number is divided by 5, print buzz; when number is divided by both 3 and 5, print fizz buzz.
Example
If n=15, you should return ["1", "2", "fizz", "4", "buzz", "fizz", "7", "8", "fizz", "buzz", "11", "fizz", "13", "14", "fizz buzz"]
*/
#include <vector>
#include <string>

using namespace std;

class Solution {
  public:
    // param n description of n
    // return a vector<string>
    vector<string> fizzBuzz(int n) {
        vector<string> results;
        // write your code here.
        // hint: you can convert int to string by stringstream:
        //     stringstream ss; ss << number;
        //     string number_str = ss.str();
        // or sprintf:
        //     char buffer[100];
        //     sprintf(buffer, "%d", number);
        for (int i = 1 ; i <= n; i++) {
            if (i % 3 == 0 && i % 5 == 0) {
                results.push_back("fizz buzz");
            } else if (i % 3 == 0) {
                results.push_back("fizz");
            } else if (i % 5 == 0) {
                results.push_back("buzz");
            } else {
                results.push_back(to_string(i));
            }
        }
        return results;
    }
};
