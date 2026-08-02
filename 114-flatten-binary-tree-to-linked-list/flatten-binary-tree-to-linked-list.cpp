class Solution {
public:
    void preorder(TreeNode* node, vector<TreeNode*>& nodes) {
        if (node) {
            nodes.push_back(node);
            preorder(node->left, nodes);
            preorder(node->right, nodes);
        }
    }

    void flatten(TreeNode* root) {
        vector<TreeNode*> nodes;

        preorder(root, nodes);

        TreeNode* prev = root;

        for (int i = 1; i < nodes.size(); i++) {
            prev->left = NULL;
            prev->right = nodes[i];
            prev = prev->right;
        }
    }
};