/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
 */

// @lc code=start
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
    void preorder(TreeNode* root, vector<int> &ans) {
        if(!root) return;

        ans.push_back(root->val);
        preorder(root->left, ans);
        preorder(root->right, ans);
        return;
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
        // stack<TreeNode*> stk;
        // TreeNode* curr = root;

        // while(!stk.empty()) {
        //     TreeNode* curr = stk.top();
        //     stk.pop();

        //     ans.push_back(curr->val);
        //     if(curr->right) stk.push(curr->right);
        //     if(curr->left) stk.push(curr->left)
        // }
    }
};
// @lc code=end

