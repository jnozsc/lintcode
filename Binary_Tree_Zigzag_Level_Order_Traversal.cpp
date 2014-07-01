/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

Example
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7


return its zigzag level order traversal as:

[
  [3],
  [20,9],
  [15,7]
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
     * @param root: The root of binary tree.
     * @return: A list of lists of integer include
     *          the zigzag level order traversal of its nodes' values
     */
  public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // write your code here
        vector<vector<int>> result;
        queue<TreeNode*> myQueue;
        if (root) {
            myQueue.push(root);
        }
        bool zigzag = false;
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
            if (zigzag) {
                reverse(currentLevel.begin(), currentLevel.end());
            }
            zigzag = !zigzag;
            result.push_back(currentLevel);
        }
        return result;
    }
};
