/*
Given a binary tree, return the preorder traversal of its nodes' values.

Note
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3


return [1,2,3].

Challenge
Can you do it without recursion?
*/
// version 1, recursion
#include <vector>
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
  public:
    /**
     * @param root: The root of binary tree.
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode* root) {
        // write your code here
        vector<int> result;
        preorderTraversalRecursion(root, result);
        return result;
    }

    void preorderTraversalRecursion(TreeNode* root, vector<int>& result) {
        if (!root) {
            return;
        }
        result.push_back(root->val);
        preorderTraversalRecursion(root->left, result);
        preorderTraversalRecursion(root->right, result);
    }
};

// version 2, iterator

#include <vector>
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
  public:
    /**
     * @param root: The root of binary tree.
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode* root) {
        // write your code here
        vector<int> result;
        if (!root) {
            return result;
        }
        vector<TreeNode*> myStack;
        myStack.push_back(root);
        while (!myStack.empty()) {
            TreeNode* current = myStack.back();
            result.push_back(current->val);
            myStack.pop_back();
            if (current->right) {
                myStack.push_back(current->right);
            }
            if (current->left) {
                myStack.push_back(current->left);
            }
        }
        return result;
    }
};
