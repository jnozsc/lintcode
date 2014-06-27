/*
Given a binary tree, return the inorder traversal of its nodes' values.

Example
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3


return [1,3,2].

Challenge Expand
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
    /**
     * @param root: The root of binary tree.
     * @return: Inorder in vector which contains node values.
     */
  public:
    vector<int> inorderTraversal(TreeNode* root) {
        // write your code here
        vector<int> result;
        inorderTraversalRecursion(root, result);
        return result;
    }

    void inorderTraversalRecursion(TreeNode* root, vector<int>& result) {
        if (!root) {
            return;
        }
        inorderTraversalRecursion(root->left, result);
        result.push_back(root->val);
        inorderTraversalRecursion(root->right, result);
    }
};

// version 2, iterator
#include <vector>
#include <stack>
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
     * @return: Inorder in vector which contains node values.
     */
  public:
    vector<int> inorderTraversal(TreeNode* root) {
        // write your code here
        vector<int> result;
        stack<TreeNode*> myStack;
        bool done = false;
        TreeNode* current = root;
        while (!done) {
            if (current) {
                myStack.push(current);
                current = current->left;
            } else {
                if (myStack.empty()) {
                    done = true;
                } else {
                    current = myStack.top();
                    myStack.pop();
                    result.push_back(current->val);
                    current = current->right;
                }
            }
        }
        return result;
    }
};
