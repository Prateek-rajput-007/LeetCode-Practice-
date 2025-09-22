class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        int fin=0;
        int maxi=INT_MIN;
        int count=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(auto it:mp){
            if(it.second>maxi){
                maxi=it.second;
            }
        }
        for(auto it:mp){
            if(maxi==it.second){
                fin+=(it.second);
            }
        }
        return fin;
    }
};