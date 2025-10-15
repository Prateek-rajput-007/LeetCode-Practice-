// class Solution {
// public:
//     long long maxTotalValue(vector<int>& arr, int k) {
//         long long sum=0;
//         int n = arr.size();
//         vector<int> ans;
//         for(int i=0;i<n;i++){
//             int maxi = INT_MIN;
//             int mini = INT_MAX;
//             for(int j=i;j<n;j++){
//                 maxi = max(maxi, arr[j]);
//                 mini = min(mini,arr[j]);
//                 ans.push_back(maxi-mini);
//             }
//         }
//         sort(ans.begin(),ans.end(),greater<int>());
//         for(auto it:ans){
//             cout<<it<<endl;
//         }
//         for(int i=0;i<k;i++){
//             sum+=ans[i];
//         }
//         return sum;
//     }
// };

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int mx = *max_element(nums.begin(), nums.end());
        int mn = *min_element(nums.begin(), nums.end());
        long long best = (long long)(mx - mn);
        return best * k;
    }
};
