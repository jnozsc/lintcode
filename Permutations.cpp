/*
Given a list of numbers, return all possible permutations.
Example
For nums [1,2,3], the permutaions are:
[
    [1,2,3],
    [1,3,2],
    [2,1,3],
    [2,3,1],
    [3,1,2],
    [3,2,1]
]
*/
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
  public:
    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > result;
        if (nums.empty()) {
            return result;
        }
        vector<int> current;
        permuteDFS(result, current, nums);
        // write your code here
        return result;
    }

    void permuteDFS(vector<vector<int> >& result, vector<int> current, vector<int> nums) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (current.empty() || find(current.begin(), current.end(), nums[i]) == current.end()) {
                current.push_back(nums[i]);
                permuteDFS(result, current, nums);
                current.pop_back();
            }
        }
    }
};
