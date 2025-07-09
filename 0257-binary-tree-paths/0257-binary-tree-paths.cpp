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
    void solve(TreeNode* root, vector<string> &ans, string temp){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            temp=temp + to_string(root->val);
            ans.push_back(temp);
            return;
        }
        string old = temp;
        temp = temp +to_string(root->val);
        temp.push_back('-');
        temp.push_back('>');
        solve(root->left,ans,temp);
        solve(root->right,ans,temp);

        //backtrack
        // temp=old;

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string temp="";
        solve(root,ans,temp);
        return ans;
    }
};