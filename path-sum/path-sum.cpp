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
    void solve(TreeNode* root, int targetSum, vector<int> &arr,bool &ok)
    {             
        if(root == NULL) return;        
        arr.push_back(root->val);
        targetSum -= root->val;
        if(root->left==NULL and root->right==NULL)
        {
            if(targetSum == 0) ok |= true;
        }
        else
        {
            solve(root->left, targetSum, arr, ok);
            solve(root->right, targetSum, arr, ok);
        }
        arr.pop_back();
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool ok = false;   
        vector<int> arr;
        solve(root, targetSum, arr, ok);
        return ok;
    }
};