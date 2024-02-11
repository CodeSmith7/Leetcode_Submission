class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(2, vector<vector<int>>(n, vector<int>(n, -1)));
        int ans = 0;

        dp[0][0][n-1] = grid[0][0] + grid[0][n-1];

        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) { // robotA
                for (int k = j + 1; k < n; k++) { // robotB
                    int maxVal = -1;
                    for (int x = -1; x <= 1; x++) { // we will have a total of 9 combinations
                        for (int y = -1; y <= 1; y++) {
                            if (j + x >= 0 && j + x < n && k + y >= 0 && k + y < n) {
                                maxVal = max(maxVal, dp[(i + 1) % 2][j + x][k + y]);
                            }
                        }
                    }
                    if (maxVal != -1) {
                        dp[i % 2][j][k] = maxVal + grid[i][j] + grid[i][k];
                    }
                    ans = max(ans, dp[i % 2][j][k]);
                }
            }
        }

        return ans;
    }
};