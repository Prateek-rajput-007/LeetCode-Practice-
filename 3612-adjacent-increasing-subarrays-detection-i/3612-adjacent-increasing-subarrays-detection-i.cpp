class Solution {
    bool isIncreasing(vector<int>& nums, int start, int end){
        for(int i=start+1; i<end; i++){
            if(nums[i]<=nums[i-1]){
                return false;
            }
        }
        return true;
    }

public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        for(int i=0; i+2*k<=nums.size(); i++){
            if(isIncreasing(nums, i, i+k) && isIncreasing(nums, i+k, i+2*k)){
                return true;
            }
        }
        return false;
    }
};