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
    void solve(TreeNode* root, vector<int>& nodes) {
        if(root == NULL) return;
        solve(root->left, nodes);
        nodes.push_back(root->val);
        solve(root->right, nodes);
    }
    
    bool isValidBST(TreeNode* root) {
        vector<int> nodes;
        solve(root, nodes);
        bool ok = true;
        for(int i=0; i<nodes.size()-1; i++)
            ok &= (nodes[i] < nodes[i+1]);
        return ok;
    }
};