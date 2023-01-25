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
        vector<int> preorder;
        if (!root) return preorder;
        stack<TreeNode*> st;
        //TreeNode* curr=root;
        st.push(root);
        while( !st.empty()){
            root= st.top();
            st.pop();
                preorder.push_back(root->val);
                if(root->right) st.push(root->right);
                //root=root->left;
                if(root->left) st.push(root->left);
        }
        return preorder;
    }
};