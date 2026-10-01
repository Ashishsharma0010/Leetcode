class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        queue<TreeNode*> pending;
        pending.push(root);

        while (!pending.empty()) {
            int levelSize = pending.size();
            vector<int> currentLevel;

            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = pending.front();
                pending.pop();
                currentLevel.push_back(node->val);

                if (node->left) pending.push(node->left);
                if (node->right) pending.push(node->right);
            }
            result.push_back(currentLevel);
        }
        return result;
    }
};