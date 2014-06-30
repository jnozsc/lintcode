/*
Given a binary tree, return the postorder traversal of its nodes' values.

Example
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3


return [3,2,1].

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
     * @return: Postorder in vector which contains node values.
     */
  public:
    vector<int> postorderTraversal(TreeNode* root) {
        // write your code here
        vector<int> result;
        postorderTraversalRecursion(root, result);
        return result;
    }

    void postorderTraversalRecursion(TreeNode* root, vector<int>& result) {
        if (!root) {
            return;
        }
        postorderTraversalRecursion(root->left, result);
        postorderTraversalRecursion(root->right, result);
        result.push_back(root->val);
    }

};

// version 2 , iterator
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
     * @return: Postorder in vector which contains node values.
     */
  public:
    vector<int> postorderTraversal(TreeNode* root) {
        // write your code here
        vector<int> result;
        if (!root) {
            return result;
        }
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* current = s.top();
            result.insert(result.begin(), current->val);
            s.pop();
            if (current->left) {
                s.push(current->left);
            }
            if (current->right) {
                s.push(current->right);
            }
        }
        return result;
    }
};
