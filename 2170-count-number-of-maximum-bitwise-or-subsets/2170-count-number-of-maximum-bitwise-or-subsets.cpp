class Solution {
public:
    int solve(vector<int> &nums, int i, int count, int r){
        if(i==nums.size()){
            if(r == count){
                return 1;
            }
            return 0;
        }
        int notTake = solve(nums,i+1,count,r);
        count = count | nums[i];
        int take = solve(nums,i+1,count,r);

        return take+notTake;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxi = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            maxi = maxi | nums[i];
        }
        return solve(nums,0,0,maxi);

    }
};