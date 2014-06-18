/*
Given a string which contains only letters. Sort it by lower case first and upper case second.

Note
It's not necessary to keep the original order of lower-case letters and upper case letters.

Example
For "abAcD", a reasonable answer is "acbAD"

Challenge
Do it in one-pass and in-place.
*/
#include <string>

using namespace std;

class Solution {
  public:
    /**
     * @param chars: The letters array you should sort.
     */
    void sortLetters(string& letters) {
        // write your code here
        int less = 0, equal = 0, larger = letters.length() - 1;
        while (equal <= larger) {
            if (letters[equal] >= 'a' && letters[equal] <= 'z') {
                swap(letters[less++], letters[equal++]);
            } else if (letters[equal] >= 'A' && letters[equal] <= 'Z') {
                swap(letters[equal], letters[larger--]);
            } else {
                equal++;
            }
        }
    }
};
