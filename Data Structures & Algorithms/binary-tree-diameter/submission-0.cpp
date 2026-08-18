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
    int sumEdges(TreeNode* root) {
        if (!root) return 0;
        return max(sumEdges(root->left), sumEdges(root->right)) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int rootDm = sumEdges(root->left) + sumEdges(root->right);
        int leftDm = diameterOfBinaryTree(root->left);
        int rightDm = diameterOfBinaryTree(root->right);
        return max(max(rootDm, leftDm), rightDm);
    }
};
