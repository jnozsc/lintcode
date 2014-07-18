/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note
You may assume that duplicates do not exist in the tree.
*/
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
     *@param inorder : A list of integers that inorder traversal of a tree
     *@param postorder : A list of integers that postorder traversal of a tree
     *@return : Root of a tree
     */
  public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // write your code here
        return buildTreeRecursion(inorder, postorder , 0, inorder.size() - 1, 0, postorder.size() - 1);
    }

    TreeNode* buildTreeRecursion(vector<int>& inorder, vector<int>& postorder, int inorderBegin, int inorderEnd, int postorderBegin, int postorderEnd) {
        if (inorderBegin < 0 || inorderEnd > inorder.size() - 1 || postorderBegin < 0 || postorderEnd > postorder.size() - 1 || inorderBegin > inorderEnd || postorderBegin > postorderEnd) {
            return NULL;
        }
        int rootNode = postorder[postorderEnd];
        TreeNode* result = new TreeNode(rootNode);
        if (postorderBegin == postorderEnd) {
            return result;
        }
        int leftChildLength = inorderBegin;
        while (inorder[leftChildLength] != rootNode) {
            leftChildLength++;
        }
        leftChildLength = leftChildLength - inorderBegin;
        int rightChildLength = inorderEnd - inorderBegin + 1 - leftChildLength - 1;
        result->left = buildTreeRecursion(inorder, postorder, inorderBegin, inorderBegin + leftChildLength - 1, postorderBegin, postorderBegin + leftChildLength - 1);
        result->right = buildTreeRecursion(inorder, postorder, inorderEnd - rightChildLength + 1, inorderEnd, postorderEnd - 1 - rightChildLength + 1, postorderEnd - 1);
        return result;
    }
};
