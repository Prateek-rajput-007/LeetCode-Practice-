class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size(), inc=1,dec=1, maxi=0;
        if(n<=1){
            return n;
        }

        for(int i=1;i<n;i++){
            if(nums[i-1]<nums[i]){
                inc++;
                dec=1;
            }
            else if(nums[i-1]>nums[i]){
                dec++;
                inc=1;
            }
            else{
                inc=1;
                dec=1;
            }
            maxi=max(maxi,max(inc,dec));
        }
        return maxi;
    }
};