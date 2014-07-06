/*
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Example
Clarification Expand
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.
*/
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
    /**
     * @param s : A string
     * @return : A string
     */
  public:
    string reverseWords(string s) {
        // write your code here
        if (s.empty()) {
            return "";
        }
        vector<string> tokens;
        stringstream ss(s);
        string item;
        while (getline(ss, item, ' ')) {
            if (!item.empty()) {
                tokens.push_back(item);
            }
        }
        if (tokens.size() == 0) {
            return "";
        }
        string result = "";
        for (int i = tokens.size() - 1; i >= 0; i--) {
            result += (tokens[i] + " ");
        }
        return result.substr(0, result.length() - 1);
    }
};
