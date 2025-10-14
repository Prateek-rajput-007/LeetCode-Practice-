class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();

        int xorr=0;
        bool flag=false;
        for(int i=0; i<n; i++) {
            xorr^=nums[i];
            if(nums[i]>0) flag=true;
        }
        if(xorr>0) return n;
        else if(flag) return n-1;
        return 0;
    }
};