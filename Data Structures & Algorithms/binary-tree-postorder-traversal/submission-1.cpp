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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<pair<TreeNode*, bool>> nodes;
        vector<int> res;
        nodes.push({root, false});
        while (!nodes.empty()) {
            auto cur = nodes.top();
            nodes.pop();
            if (cur.first) {
                if (cur.second) {
                    res.push_back(cur.first->val);
                } else {
                    nodes.push({cur.first, true});
                    nodes.push({cur.first->right, false});
                    nodes.push({cur.first->left, false});
                }
            }
        }

        return res;
    }
};