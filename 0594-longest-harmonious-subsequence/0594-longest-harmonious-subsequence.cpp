class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int maxi = INT_MIN, start=0, end=0;
        while(end < n){
            while(nums[end]-nums[start] > 1){
                start++;
            }
            if(nums[end]-nums[start] == 1){
                maxi = max(maxi, (end-start + 1));
            }
            end++;
        }
        return maxi==INT_MIN ? 0: maxi;
    }
};