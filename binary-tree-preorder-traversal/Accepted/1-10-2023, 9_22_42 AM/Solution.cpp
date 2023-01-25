// https://leetcode.com/problems/binary-tree-preorder-traversal

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
    TreeNode *cur = root;
    while (cur) {
        TreeNode *mostRight = cur ->left;
        if (mostRight) {
            while (mostRight->right != NULL && mostRight->right != cur) {
                mostRight = mostRight ->right;
            }
            if (mostRight->right == NULL) {
                result.push_back(cur->val);
                mostRight->right = cur;
                cur = cur ->left;
                continue;
            } else {
                mostRight->right = NULL;
            }
        } else {
            result.push_back(cur->val);
        }
        cur = cur->right;
    }
    
    return result;
    }
};