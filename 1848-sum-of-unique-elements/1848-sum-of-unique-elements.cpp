class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
       /* int freq[101]={0};
        int count=0;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]+=1;
        }
        for(int i=0;i<nums.size();i++){
            if(freq[nums[i]]==1){
                count+=nums[i];
            }
        }
        return count;*/
        int sum=0;
       map<int,int>mp;
        
       for(auto x:nums)
       mp[x]++;
        
       for(auto m:mp)
       {
           if(m.second==1)
               sum+=m.first;
       }
        return sum;
    }
};