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
    void recInorder(TreeNode* root, vector<int>& res) {
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        if (left) {
            recInorder(left, res);
        } 
        res.push_back(root->val);
        if (right) {
            recInorder(right, res);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        recInorder(root, result);
        return result;
    }
};