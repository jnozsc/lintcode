/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

Example
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7


return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
]
Challenge Expand
Using only 1 queue to implement it
*/
#include <vector>
#include <queue>
#include "lintcode.h"

using namespace std;

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: Level order a list of lists of integer
     */
  public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // write your code here
        queue<TreeNode*> myQueue;
        if (root) {
            myQueue.push(root);
        }
        vector<vector<int>> result;
        while (!myQueue.empty()) {
            vector<int> currentLevel;
            int size = myQueue.size();
            for (int i = 0; i < size; i++) {
                TreeNode* current = myQueue.front();
                myQueue.pop();
                currentLevel.push_back(current->val);
                if (current->left) {
                    myQueue.push(current->left);
                }
                if (current->right) {
                    myQueue.push(current->right);
                }
            }
            result.push_back(currentLevel);
        }
        return result;
    }
};
