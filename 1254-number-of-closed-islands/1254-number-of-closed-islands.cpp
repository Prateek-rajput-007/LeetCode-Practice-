class Solution {
public:
    bool isValid(int i, int j, int n, int m, vector<vector<int>>& g){
        if(i>=0 && i<n && j>=0 && j<m && g[i][j] == 0){
            return true;
        }
        return false;
    }
    void solve(int i, int j, int n, int m, vector<vector<int>>& g){

        if(!isValid(i,j,n,m,g)){
            return;
        }
        g[i][j] = 1;

        solve(i,j-1,n,m,g);
        solve(i-1,j,n,m,g);
        solve(i+1,j,n,m,g);
        solve(i,j+1,n,m,g);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i*j == 0 || i == n-1 || j == m-1){
                    if(grid[i][j] == 0){
                        solve(i,j,n,m,grid);
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                    if(grid[i][j] == 0){
                        solve(i,j,n,m,grid);
                        ans++;
                    }
            }
        }
        return ans;
    }
};