class Solution {
public:
    // int dp[101][101];

    // int solve(vector<vector<int>>& m, int row, int col, int n) {
    //     if (row == n - 1) {
    //         return m[row][col];
    //     }
    //     if (dp[row][col] != -1) {
    //         return dp[row][col];
    //     }
    //     int mini = INT_MAX;
    //     int sum = m[row][col];

    //     if (row + 1 < n && col - 1 >= 0) {
    //         mini = min(mini, sum + solve(m, row + 1, col - 1, n));
    //     }
    //     if (row + 1 < n) {
    //         mini = min(mini, sum + solve(m, row + 1, col, n));
    //     }
    //     if (row + 1 < n && col + 1 < n) {
    //         mini = min(mini, sum + solve(m, row + 1, col + 1, n));
    //     }
    //     return dp[row][col] = mini;
    // }

    // int minFallingPathSum(vector<vector<int>>& matrix) {
    //     int n = matrix.size();

    //     memset(dp, -1, sizeof(dp));
    //     int mini = INT_MAX;
    //     int row = 0;
    //     for (int col = 0; col < n; col++) {
    //         mini = min(mini, solve(matrix, row, col, n));
    //     }

    //     return mini;
    // }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int j=0;j<n;j++)
        {
            dp[0][j] = matrix[0][j];
        }
        
        for(int i=1;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                // for oth col we dont have col-1
                if(j == 0)
                    dp[i][j] = matrix[i][j] + min(dp[i-1][j],dp[i-1][j+1]);
                
                else if(j == n-1)
                    dp[i][j] = matrix[i][j] + min(dp[i-1][j-1],dp[i-1][j]);
                
                else
                {
                    dp[i][j] = matrix[i][j] + min(dp[i-1][j-1],
                                                min(dp[i-1][j],dp[i-1][j+1]));
                }
            }
        }
        
        int ans = 1e9;
        // find min among last row
        for(int j=0;j<n;j++)
        {
            ans = min(ans,dp[m-1][j]);
        }
        return ans;
    }
};