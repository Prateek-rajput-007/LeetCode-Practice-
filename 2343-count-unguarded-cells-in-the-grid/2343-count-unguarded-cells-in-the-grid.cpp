class Solution {
public:
    bool isValid(int i, int j, int m, int n, vector<vector<int>>& mat) {
        if (i < 0 || j < 0 || i >= m || j >= n)
            return false; // out of bounds
        if (mat[i][j] == 1 || mat[i][j] == 2)
            return false; // guard or wall blocks
        return true;
    }

    // DFS that continues in a single direction only
    void solve(int i, int j, int m, int n, vector<vector<int>>& mat, int dx, int dy) {
        int ni = i + dx, nj = j + dy;

        if (!isValid(ni, nj, m, n, mat))
            return;

        mat[ni][nj] = 3; // mark as guarded
        solve(ni, nj, m, n, mat, dx, dy); // continue in same direction
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<int>> mat(m, vector<int>(n, 0));

        // Mark guards as 1 and walls as 2
        for (auto &g : guards)
            mat[g[0]][g[1]] = 1;

        for (auto &w : walls)
            mat[w[0]][w[1]] = 2;

        // For each guard, run DFS in 4 directions
        for (auto &g : guards) {
            int i = g[0], j = g[1];
            solve(i, j, m, n, mat, -1, 0); // up
            solve(i, j, m, n, mat, 1, 0);  // down
            solve(i, j, m, n, mat, 0, -1); // left
            solve(i, j, m, n, mat, 0, 1);  // right
        }

        // Count unguarded cells
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0)
                    count++;
            }
        }

        // Debug grid (optional)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }

        return count;
    }
};
