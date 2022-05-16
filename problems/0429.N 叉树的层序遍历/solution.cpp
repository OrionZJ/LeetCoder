/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> que;
        if (root) que.push(root);
        vector<vector<int>> res;
        while (!que.empty()) {
            auto size = que.size();
            vector<int> vec;
            for (int i = 0; i < size; ++i) {
                Node* node = que.front();
                que.pop();
                vec.push_back(node->val);
                for (auto j : node->children) {
                    if (j) que.push(j);
                }
            }
            res.push_back(vec);
        }
        return res;
    }
};