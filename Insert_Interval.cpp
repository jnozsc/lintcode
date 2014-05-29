/*
Given a non-overlapping interval list which is sorted by start point. Insert a new interval into it, make sure the list is still in order and non-overlapping (merge intervals if necessary).
Example
Insert [2, 5] into [[1,2], [5,9]], we get [[1,9]].
Insert [3, 4] into [[1,2], [5,9]], we get [[1,2], [3,4], [5,9]].
*/
#include <vector>
#include <algorithm>
#include "lintcode.h"

using namespace std;

/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */

bool compareInterval(Interval a, Interval b) {
    if (a.start == b.start) return a.end < b.end;
    else return a.start < b.start;
}

class Solution {
  public:
    /**
     * Insert newInterval into intervals.
     * @param intervals: Sorted interval list.
     * @param newInterval: new interval.
     * @return: A new interval list.
     */

    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> result;
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end(), compareInterval);
        int n = intervals.size();
        int i = 0;
        while (i < n) {
            result.push_back(intervals[i]);
            i++;
            while (i < n && intervals[i].start <= result.back().end) {
                result.back().end = max(result.back().end, intervals[i].end);
                i++;
            }
        }
        return result;
    }
};
