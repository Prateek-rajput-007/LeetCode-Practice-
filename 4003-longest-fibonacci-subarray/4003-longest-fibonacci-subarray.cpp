class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int curr_len = 2;

        for (int i = 2; i < n; i++) {
            if (nums[i - 1] + nums[i - 2] == nums[i])
                curr_len++;
            else
                curr_len = 2;

            maxi = max(maxi, curr_len);
        }
        return maxi;
    }
};