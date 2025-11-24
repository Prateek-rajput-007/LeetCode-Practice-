class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int rem=0,n=nums.size();
        vector<bool>v(n,0);
        for(int i=0;i<n;i++){
            rem=(rem*2 +nums[i])%5;
            if(rem==0)v[i]=true;
        }
        return v;
    }
};