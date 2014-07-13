/*
Given a string source and a string target, find the minimum window in source which will contain all the characters in target.

Note
If there is no such window in source that covers all characters in target, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in source.

Example
source = "ADOBECODEBANC" target = "ABC" Minimum window is "BANC".

Challenge Expand
Can you do it in time complexity O(n) ?

Clarification Expand
Should the characters in minimum window has the same order in target?

    - Not necessary.
*/
#include <string>
#include <map>

using namespace std;

class Solution {
  public:
    /**
     * @param source: A string
     * @param target: A string
     * @return: A string denote the minimum window
     *          Return "" if there is no such a string
     */
    string minWindow(string& source, string& target) {
        // write your code here
        string S = source;
        string T = target;
        map<char, int> T_has;
        map<char, int> now_we_has;

        // init hashtable
        for (int i = 0; i < T.length(); i++) {
            if (T_has.find(T[i]) != T_has.end()) {
                T_has[T[i]]++;
            } else {
                T_has[T[i]] = 1;
                now_we_has[T[i]] = 0;
            }
        }
        // for loop
        int count = 0;
        int minWinBegin = -1;
        int minWinEnd = S.length();
        int begin = 0;
        for (int end = 0; end < S.length(); end++) {
            char c = S[end];
            if (T_has.find(c) != T_has.end()) {
                now_we_has[c]++;
                if (now_we_has[c] <= T_has[c]) {
                    count++;
                }
                // find one valid substr
                if (count == T.length()) {
                    //while (1) S[begin] is useless char, (2) now_we_has[S[begin]]> T_has[S[begin]]
                    while (T_has.find(S[begin]) == T_has.end() || now_we_has[S[begin]] > T_has[S[begin]]) {
                        if ((T_has.find(S[begin]) != T_has.end() && now_we_has[S[begin]] > T_has[S[begin]])) {
                            now_we_has[S[begin]]--;
                        }
                        begin++;
                    }
                    if (end - begin < minWinEnd - minWinBegin) {
                        minWinEnd = end;
                        minWinBegin = begin;
                    }
                }
            }
        }
        return minWinBegin == -1 ? "" : S.substr(minWinBegin, minWinEnd - minWinBegin + 1);
    }
};
