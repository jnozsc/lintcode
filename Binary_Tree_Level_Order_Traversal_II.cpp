/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

Example
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7


return its bottom-up level order traversal as:

[
  [15,7],
  [9,20],
  [3]
]
*/
#include <vector>
#include <queue>
#include <algorithm>
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
     * @param root : The root of binary tree.
     * @return : buttom-up level order a list of lists of integer
     */
  public:
    vector<vector<int>> levelOrderButtom(TreeNode* root) {
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
        reverse(result.begin(), result.end());
        return result;
    }
};
