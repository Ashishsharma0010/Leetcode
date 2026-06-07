class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        unordered_set<int> children;
        
        for (auto& d : descriptions) {
            int p = d[0], c = d[1], left = d[2];
            if (!nodes.count(p)) nodes[p] = new TreeNode(p);
            if (!nodes.count(c)) nodes[c] = new TreeNode(c);
            if (left) nodes[p]->left = nodes[c];
            else nodes[p]->right = nodes[c];
            children.insert(c);
        }
        
        for (auto& [val, node] : nodes)
            if (!children.count(val)) return node;
        
        return nullptr;
    }
};