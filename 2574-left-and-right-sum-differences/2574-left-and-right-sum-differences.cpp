class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
          int n=nums.size(),sum=0,sum1=0;
        vector<int>left,right;
        for(int i=0;i<n;i++){
            sum=sum+nums[i];
            sum1=sum1+nums[i];
        }       
        for(int i=0;i<n;i++){
            sum=sum-nums[i];
            right.push_back(sum);
        }
        for(int i=n-1;i>=0;i--){
            sum1=sum1-nums[i];
            left.push_back(sum1);
        }
        reverse(left.begin(),left.end());
        vector<int>ans;
        for(int i=0;i<n;i++){
            ans.push_back(abs(left[i]-right[i]));
        }
        return ans;
    }
};