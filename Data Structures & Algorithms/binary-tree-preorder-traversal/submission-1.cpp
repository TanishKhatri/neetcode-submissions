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
        stack<TreeNode*> nodes;
        vector<int> result;
        TreeNode* cur = root;
        while (cur || !nodes.empty()) {
            if (cur) {
                result.push_back(cur->val);
                nodes.push(cur->right);
                nodes.push(cur->left);
            }
            cur = nodes.top();
            nodes.pop();
        }

        return result;
    }
};