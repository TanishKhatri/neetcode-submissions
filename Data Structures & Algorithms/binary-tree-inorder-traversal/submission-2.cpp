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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> nodes;
        vector<int> result;
        TreeNode* cur = root;
        while (cur || !nodes.empty()) {
            while (cur) {
                nodes.push(cur);
                cur = cur->left;
            }
            TreeNode* top = nodes.top();
            result.push_back(top->val);
            nodes.pop();
            cur = top->right;
        }

        return result;
    }
};