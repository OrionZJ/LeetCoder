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
    int rob(TreeNode* root) {
        vector<int> result = robTree(root);
        // 长度为2的数组，0：不偷，1：偷
        return max(result[0], result[1]);
    }

    vector<int> robTree(TreeNode* cur) {
        if (cur == NULL) return vector<int> {0, 0};
        vector<int> left = robTree(cur->left);
        vector<int> right = robTree(cur->right);
        // 偷当前节点
        int val_0 = max(left[0], left[1]) + max(right[0], right[1]);
        // 不偷当前节点
        int val_1 = cur->val + left[0] + right[0];
        return vector<int> {val_0, val_1};
    }
};