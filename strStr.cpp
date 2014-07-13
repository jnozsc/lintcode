/*
strstr (a.k.a find sub string), is a useful function in string operation. You task is to implement this function. For a given source string and a target string, you should output the "first" index(from 0) of target string in source string. If target is not exist in source, just return -1.
Example
If source="source" and target="target", return -1.
If source="abcdabcdefg" and target="bcd", return 1.
*/
#include <cstring>
using namespace std;

class Solution {
  public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char* source, const char* target) {
        // write your code here
        if (target == NULL) {
            return -1;
        }
        if (strlen(target) == 0) {
            return 0;
        }
        if (source == NULL || strlen(source) == 0) {
            return -1;
        }
        int i = 0, j = 0;
        int here = 0;
        while (1) {
            if (target[i] == source[j]) {
                if (here == 0) {
                    here = j;
                }
                i++;
                j++;
                if (i >= strlen(target)) {
                    return here;
                }
                if (j >= strlen(source)) {
                    return -1;
                }
            } else {
                j++;
                i = 0;
                here = 0;
            }
        }
    }
};
