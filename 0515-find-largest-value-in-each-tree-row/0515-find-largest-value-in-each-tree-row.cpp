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
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        int sum=0,maxi=INT_MIN;
        vector<int> v;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            maxi=INT_MIN;
            for(int i=0;i<size;i++){
                sum=0;
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
                sum+=temp->val;
                maxi=max(sum,maxi);
            }
            v.push_back(maxi);
        }
        return v;
    }
};