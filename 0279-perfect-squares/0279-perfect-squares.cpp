class Solution {
public:
    int solve(int n){
        //base case
        if(n==0){
            return 0;
        }
        int ans = INT_MAX;

        for(int i=1;i*i<=n;i++){
            ans=min(ans,1+solve(n-i*i));
        }
        return ans;
    }

    int solveMem(int n,vector<int>& dp){
        //base case
        if(n==0){
            return 0;
        }
        int ans = INT_MAX;
        if(dp[n]!=-1){
            return dp[n];
        }
        for(int i=1;i*i<=n;i++){
            ans=min(ans,1+solveMem(n-i*i,dp));
        }
        return dp[n]=ans;
    }
    
    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        return solveMem(n,dp);
    }
};