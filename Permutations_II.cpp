/*
Given a list of numbers with duplicate number in it. For example [1,2,2], find all unique permutations.
Example
For numbers [1,2,2] the unique permutations are:
[
    [1,2,2],
    [2,1,2],
    [2,2,1]
]
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        // write your code here
        sort(nums.begin(), nums.end());
        vector<vector<int> > result;
        vector<bool> visited(nums.size(), false);
        vector<int> currentSolution;
        permuteUniqueDFS(result, currentSolution, nums, visited);
        sort(result.begin(), result.end());
        return result;
    }

    void permuteUniqueDFS(vector<vector<int> >& result, vector<int> currentSolution, vector<int> nums, vector<bool> visited) {
        if (currentSolution.size() == nums.size()) {
            if (find(result.begin(), result.end(), currentSolution) == result.end()) {
                result.push_back(currentSolution);
            }
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i] == false) {
                if (i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == false) {
                    continue; // fix Time Limit Exceeded
                }
                visited[i] = true;
                currentSolution.push_back(nums[i]);
                permuteUniqueDFS(result, currentSolution, nums, visited);
                visited[i] = false;
                currentSolution.pop_back();
            }
        }
    }
};
