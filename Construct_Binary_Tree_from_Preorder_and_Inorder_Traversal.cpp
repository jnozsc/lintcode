/*
Given preorder and inorder traversal of a tree, construct the binary tree.

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
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
  public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // write your code here
        return buildTreeRecursion(preorder, inorder , 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode* buildTreeRecursion(vector<int>& preorder, vector<int>& inorder, int preorderBegin, int preorderEnd, int inorderBegin, int inorderEnd) {
        if (preorderBegin < 0 || preorderEnd > preorder.size() - 1 || inorderBegin < 0 || inorderEnd > inorder.size() - 1 || preorderBegin > preorderEnd || inorderBegin > inorderEnd) {
            return NULL;
        }
        int rootNode = preorder[preorderBegin];
        TreeNode* result = new TreeNode(rootNode);
        if (preorderBegin == preorderEnd) {
            return result;
        }
        int leftChildLength = inorderBegin;
        while (inorder[leftChildLength] != rootNode) {
            leftChildLength++;
        }
        leftChildLength = leftChildLength - inorderBegin;
        int rightChildLength = preorderEnd - preorderBegin + 1 - leftChildLength - 1;
        result->left = buildTreeRecursion(preorder, inorder, preorderBegin + 1, preorderBegin + 1 + leftChildLength - 1, inorderBegin, inorderBegin + leftChildLength - 1);
        result->right = buildTreeRecursion(preorder, inorder, preorderEnd - rightChildLength + 1, preorderEnd, inorderEnd - rightChildLength + 1, inorderEnd);
        return result;
    }
};
