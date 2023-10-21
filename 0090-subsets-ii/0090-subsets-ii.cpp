class Solution {
private: 
    void subsetsWithDup(vector<int>& nums, vector<vector<int>>& ans, vector<int>& v, int i){
        if(i==nums.size()){
            ans.push_back(v);
            return;
        }
        //include
        v.push_back(nums[i]);
        subsetsWithDup(nums,ans,v,i+1);
        v.pop_back();

        while(i+1<nums.size() && nums[i]==nums[i+1]){
            i++;
        }
        //exclude
        subsetsWithDup(nums,ans,v,i+1);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(nums.begin(),nums.end());
        subsetsWithDup(nums,ans,v,0);
        return ans;
    }
};