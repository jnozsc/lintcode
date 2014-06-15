/*
Given a set of distinct integers, return all possible subsets.

Note
Elements in a subset must be in non-descending order.

The solution set must not contain duplicate subsets.
*/
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
  public:
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > result;
        // write your code here
        vector<int> emptySet;
        result.push_back(emptySet);
        if (nums.size() == 0) {
            return result;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int size = result.size();
            for (int j = 0; j < size; j++) {
                vector<int> newSubset = result[j];
                newSubset.push_back(nums[i]);
                result.push_back(newSubset);
            }
        }
        return result;
    }
};
