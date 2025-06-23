class Solution {
public:
    int solve(vector<int>& nums, int goal){
        int n = nums.size();
        if (goal < 0) return 0;
        
        int sum=0,count=0,start=0,end=0;
        while(end < n){
            sum = sum + nums[end];

            while(sum > goal){
                sum-=nums[start];
                start++;
            }
            count+=(end-start+1);
            end++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums,goal)-solve(nums,goal-1);
    }
};