class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int K = k;
        int n = nums.size();
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }
        vector<int> index;
        while(k>0){
         index.push_back(pq.top().second);
         pq.pop();
         k--;
        }
        sort(index.begin(),index.end());
        vector<int> ans(K,0);
        for(int i=0;i<K;i++){
            ans[i] = nums[index[i]];
        }
        return ans;
    }
};