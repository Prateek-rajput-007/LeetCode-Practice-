class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 0){
                nums[i] = abs(nums[i]);
            }
        }
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = nums.size()-1;
        long long val = 0;
        while(i<=j){
            if(i<j){
                val += (nums[j]*nums[j]);
                val -= (nums[i]*nums[i]);
            }
            else if(i == j){
                val += (nums[j]*nums[j]);
            }
            i++;
            j--;
        }
        return val;
    }
};