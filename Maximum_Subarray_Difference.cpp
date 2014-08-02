/*
Given an array with integers. Find two non-overlapping subarrays A and B, which |SUM(A) - SUM(B)| is the largest. Return the largest difference.
Example
for [1, 2, -3, 1], return 6
*/
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
  public:
    /**
     * @param v: A list of integers
     * @return: An integer indicate the value of maximum difference between two
     *          Subarrays
     */
    int maxDiffSubArrays(vector<int> v) {
        // write your code here
        int tmpMin, tmpMax;
        int maxTo[v.size()];
        int maxFrom[v.size()];
        int minTo[v.size()];
        int minFrom[v.size()];
        maxTo[0] = v[0];
        minTo[0] = v[0];
        tmpMin = v[0];
        tmpMax = v[0];
        for (int i = 1; i < v.size(); i++) {
            if (tmpMax < 0) {
                tmpMax = v[i];
            } else {
                tmpMax += v[i];
            }
            maxTo[i] = max(tmpMax, maxTo[i - 1]);
            if (tmpMin >= 0) {
                tmpMin = v[i];
            } else {
                tmpMin += v[i];
            }
            minTo[i] = min(tmpMin, minTo[i - 1]);
        }
        tmpMin = v[v.size() - 1];
        tmpMax = v[v.size() - 1];
        minFrom[v.size() - 1] = v[v.size() - 1];
        maxFrom[v.size() - 1] = v[v.size() - 1];
        for (int i = v.size() - 2; i >= 0; i--) {
            if (tmpMax < 0) {
                tmpMax = v[i];
            } else {
                tmpMax += v[i];
            }
            maxFrom[i] = max(tmpMax, maxFrom[i + 1]);
            if (tmpMin >= 0) {
                tmpMin = v[i];
            } else {
                tmpMin += v[i];
            }
            minFrom[i] = min(tmpMin, minFrom[i + 1]);
        }
        int result = max(maxTo[0] - minFrom[1],  maxFrom[1] - minTo[0]);
        for (int i = 1; i < v.size() - 1; i++) {
            result = max(result, max(maxTo[i] - minFrom[i + 1], maxFrom[i + 1] - minTo[i]));
        }
        cout << result << endl;
    }
};
