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
private:

    int countNodes(TreeNode* root){
        if(!root)
            return 0;
        int left=countNodes(root->left);
        int right=countNodes(root->right);
    return left+right+1;
    }

    int sumSubtree(TreeNode* root){
        if(!root)
            return 0;
    return root->val+sumSubtree(root->left)+sumSubtree(root->right);
    }

public:
    int averageOfSubtree(TreeNode* root) {
        // return sumSubtree(root);
        // return countNodes(root);
    int countOfnodes=0;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        int sum=0;
        int count=0;
        TreeNode* root=q.front();
        q.pop();
        
        count=countNodes(root);
        sum=sumSubtree(root);
        
        if((sum/count)==root->val)
            countOfnodes++;

        if(root->left)
            q.push(root->left);

        if(root->right)
            q.push(root->right);
    }
return countOfnodes;
    }
};