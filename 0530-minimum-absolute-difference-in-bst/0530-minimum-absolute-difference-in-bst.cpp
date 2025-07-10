class Solution {
public:
    void inorder(TreeNode* root, vector<int>& nums){
        if(!root) return;

        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> nums;
        inorder(root, nums);
        int ans = INT_MAX;
        int n = nums.size();
        for(int i = 1; i<n; i++){
            ans = min(ans, abs(nums[i-1] - nums[i]));
        }
        return ans;
    }
};