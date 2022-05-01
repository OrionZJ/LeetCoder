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
private:
    int res;
    int traversal(TreeNode* cur) {
        if (cur == NULL) return 2;
        int left = traversal(cur->left);
        int right = traversal(cur->right);
        if (right == 2 && left == 2) return 0;
        if (right == 0 || left == 0) {
            res++;
            return 1;
        }
        if (right == 1 || left == 1) return 2;
        return -1;
    }
public:
    int minCameraCover(TreeNode* root) {
        res = 0;
        if (traversal(root) == 0) res++;
        return res;     
    }
};