/*
Given a list of numbers that may has duplicate numbers, return all possible subsets

Note
Each element in a subset must be in non-descending order.

The ordering between two subsets is free.

The solution set must not contain duplicate subsets.
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    vector<vector<int> > subsetsWithDup(const vector<int>& nums) {
        vector<vector<int> > result;
        // write your code here
        vector<int> emptySubset;
        result.push_back(emptySubset);
        if (nums.size() == 0) {
            return result;
        }
        vector<int> numsCopy(nums.begin(), nums.end());
        sort(numsCopy.begin(), numsCopy.end());
        for (int i = 0; i < numsCopy.size(); i++) {
            int size = result.size();
            for (int j = 0; j < size; j++) {
                vector<int> newSubset = result[j];
                newSubset.push_back(numsCopy[i]);
                if (find(result.begin(), result.end(), newSubset) == result.end()) {
                    result.push_back(newSubset);
                }
            }
        }
        return result;
    }
};
