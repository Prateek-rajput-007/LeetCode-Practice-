class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans=-1;
        int mini = nums[0];
        int n = nums.size();
        for(int i=1;i<n;i++){
            mini = min(mini,nums[i]);
            if(nums[i] > mini){
                ans = max(ans, (nums[i]-mini));
            }
        }
        return ans;
    }
};