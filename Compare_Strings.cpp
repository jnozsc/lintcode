/*
Compare two strings A and B, determine whether A contains all of the characters in B.

The characters in string A and B are all Upper Case letters.

Example
For A = "ABCD", B = "ABC", return true.

For A = "ABCD" B = "AABC", return false.
*/
#include <string>
#include <set>

using namespace std;

class Solution {
  public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true
     *           else return false
     */
    bool compareStrings(string A, string B) {
        // write your code here
        if (B.empty()) {
            return true;
        }
        if (A.empty()) {
            return false;
        }
        multiset<char> mySet;
        for (int i = 0; i < A.length(); i++) {
            mySet.insert(A[i]);
        }
        for (int i = 0; i < B.length(); i++) {
            if (mySet.find(B[i]) == mySet.end()) {
                return false;
            } else {
                mySet.erase(mySet.find(B[i]));
            }
        }
        return true;
    }
};
