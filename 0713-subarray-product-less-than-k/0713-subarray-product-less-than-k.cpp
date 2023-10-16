class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0;
        int x = 1, i = 0, j = 0;
        while(j<nums.size()){
            x *= nums[j++];
            while(x>=k && i<j){
                x /= nums[i];
                i++;
            }
            ans += j-i;
        }
        return ans;
    }
};
//Do Upvote if you got the solution