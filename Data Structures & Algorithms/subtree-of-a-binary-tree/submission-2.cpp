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
    bool contains(TreeNode* r1, TreeNode* r2) {
        if (!r1 && !r2) {
            return true;
        } else if (!r1 && r2) {
            return false;
        } else if (r1 && !r2) {
            return false;
        }

        if (r1->val != r2->val) {
            return false;
        } else {
            bool leftCheck = contains(r1->left, r2->left);
            bool rightCheck = contains(r1->right, r2->right);

            return leftCheck && rightCheck;
        }
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) {
            return true;
        } else if (root && !subRoot) {
            return true;
        } else if (!root && subRoot) {
            return false;
        }

        if (root->val != subRoot->val) {
            bool leftCheck = isSubtree(root->left, subRoot);
            bool rightCheck = isSubtree(root->right, subRoot);

            return leftCheck || rightCheck;
        } else {
            bool doesContain = contains(root, subRoot);

            if (!doesContain) {
                bool leftCheck = isSubtree(root->left, subRoot);
                bool rightCheck = isSubtree(root->right, subRoot);

                return leftCheck || rightCheck;
            }

            return true; 
        }
    }
};
