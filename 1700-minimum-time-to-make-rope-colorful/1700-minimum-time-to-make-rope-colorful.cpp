class Solution {
public:
    int minCost(string colors, vector<int>& nums) {
        int curr=0,pre=0;
        int time=0;
        for(int i=0;i<nums.size();i++){

            if( i>0 && colors[i]!=colors[i-1]){
                pre=0;
            }
            curr = nums[i];
            time += min(pre,curr);
            pre = max(pre,curr);
        }
        return time;
    }
};