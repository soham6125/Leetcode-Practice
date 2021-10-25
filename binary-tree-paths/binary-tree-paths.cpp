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
    void solve(TreeNode* root, vector<int> &arr, vector<vector<int>> &ans)
    {             
        if(root == NULL) return;        
        arr.push_back(root->val);
        if(root->left==NULL and root->right==NULL)
        {
            ans.push_back(arr);
        }
        else
        {
            solve(root->left, arr, ans);
            solve(root->right, arr, ans);
        }
        arr.pop_back();
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> arr;        
        solve(root, arr, ans);
        vector<string> res;
        for(auto it:ans) 
        {
            string s;
            for(auto itt:it)
            {
                // cout << itt << " ";
                s += to_string(itt);
                s += "->";
            }
            // cout << endl;
            s.pop_back();
            s.pop_back();
            res.push_back(s);
        }
        return res;
    }

};