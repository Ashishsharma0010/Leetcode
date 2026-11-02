class Solution {
public:
    int maxSum;

    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        dfs(root);
        return maxSum;
    }

    int dfs(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        // Ignore negative contributions.
        int leftGain = max(0, dfs(node->left));
        int rightGain = max(0, dfs(node->right));

        // Maximum path passing through the current node.
        int currentSum = node->val + leftGain + rightGain;

        maxSum = max(maxSum, currentSum);

        // Return the maximum one-sided path to the parent.
        return node->val + max(leftGain, rightGain);
    }
};