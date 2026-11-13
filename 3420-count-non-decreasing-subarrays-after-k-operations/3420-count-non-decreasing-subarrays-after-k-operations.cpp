#include <vector>
#include <deque>
#include <utility>

using namespace std;

class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        deque<pair<long long, int>> dq;
        long long cost = 0;
        long long ans = 0;
        int r = n - 1;
        
        for (int l = n - 1; l >= 0; --l) {
            long long x = nums[l];
            int cnt = 1;
            
            while (!dq.empty() && dq.front().first < x) {
                auto [val, c] = dq.front();
                dq.pop_front();
                cost += (x - val) * c;
                cnt += c;
            }
            
            dq.emplace_front(x, cnt);
            
            while (cost > k) {
                cost -= dq.back().first - nums[r];
                if (--dq.back().second == 0) {
                    dq.pop_back();
                }
                --r;
            }
            
            ans += (r - l + 1);
        }
        
        return ans;
    }
};