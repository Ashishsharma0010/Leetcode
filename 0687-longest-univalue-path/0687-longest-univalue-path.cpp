class Solution {
public:
    int longestPath = 0;

    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return longestPath;
    }

    int dfs(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int left = dfs(node->left);
        int right = dfs(node->right);

        int leftPath = 0;
        int rightPath = 0;

        if (node->left && node->left->val == node->val) {
            leftPath = left + 1;
        }

        if (node->right && node->right->val == node->val) {
            rightPath = right + 1;
        }

        longestPath = max(longestPath, leftPath + rightPath);

        return max(leftPath, rightPath);
    }
};