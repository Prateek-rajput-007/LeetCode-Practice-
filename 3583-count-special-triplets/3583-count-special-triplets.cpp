class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        long long ans = 0;
        unordered_map<int, int> mp, mpp;
        for(auto i : nums) mpp[i]++;
        for(auto i : nums) {
            mpp[i]--;
            ans += (long long)(mp[2*i]) * mpp[2*i];
            ans %= (int)(1e9 + 7);
            mp[i]++;
        }
        return int(ans);
    }
};