class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0,count=0,res=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                count++;
            }
            while(count>k){
                if(nums[left]==0){
                    count--;
                }
                left++;
            }
            res=max(res,i-left+1);
        }
        return res;
    }
};