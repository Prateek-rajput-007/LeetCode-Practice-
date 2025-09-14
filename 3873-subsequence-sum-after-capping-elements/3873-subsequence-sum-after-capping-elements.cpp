// class Solution {
// public:
//     bool dfs(int i, int sum, vector<int>& capped, vector<vector<int>>& memo) {
//         if (sum == 0) return true;          // target reached
//         if (i == capped.size()) return false; // end of array
//         if (memo[i][sum] != -1) return memo[i][sum];

//         // Option 1: skip element
//         bool notTake = dfs(i + 1, sum, capped, memo);

//         // Option 2: take element (if possible)
//         bool take = false;
//         if (capped[i] <= sum) {
//             take = dfs(i + 1, sum - capped[i], capped, memo);
//         }

//         return memo[i][sum] = (take || notTake);
//     }



//     vector<bool> subsequenceSumAfterCapping(vector<int>& nums, int k) {
//          int n = nums.size();
//         vector<bool> ans(n, false);

//         for (int x = 1; x <= n; x++) {
//             // Cap nums by x
//             vector<int> capped;
//             for (int v : nums) capped.push_back(min(v, x));

//             // Memo table: size n x (k+1)
//             vector<vector<int>> memo(n, vector<int>(k+1, -1));

//             // Solve with recursion + memo
//             ans[x-1] = dfs(0, k, capped, memo);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<bool> subsequenceSumAfterCapping(vector<int>& nums, int k) {
        int n = nums.size();

        deque<int> q(nums.begin(), nums.end());
        vector<bool> ans(n), dp(k + 1, false);
        dp[0] = true;

        sort(q.begin(), q.end());
        for (int x = 1; x <= n; x++) {
            // Add all numbers <= x into our subset-sum DP
            while (!q.empty() && q.front() <= x) {
                int val = q.front();
                for (int j = k; j - val >= 0; j--) {
                    dp[j] = dp[j] || dp[j - val];
                }
                q.pop_front();
            }

            int available = q.size(); // numbers >= x, they cap to x
            for (int val = k; val >= 0; val--) {
                if (!dp[val]) continue;
                if ((k - val) % x != 0) continue;
                int need = (k - val) / x;
                if (need <= available) {
                    ans[x - 1] = true;
                    break;
                }
            }
        }
        
        return ans;
    }
};