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
    void solve(TreeNode* root, int targetSum, vector<int> &arr, vector<vector<int>> &ans)
    {             
        if(root == NULL) return;        
        arr.push_back(root->val);
        targetSum -= root->val;
        if(root->left==NULL and root->right==NULL)
        {
            if(targetSum == 0) ans.push_back(arr);
        }
        else
        {
            solve(root->left, targetSum, arr, ans);
            solve(root->right, targetSum, arr, ans);
        }
        arr.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> arr;        
        solve(root, targetSum, arr, ans);
        return ans;
    }
};