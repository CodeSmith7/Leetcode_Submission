class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n = grid.size();
        for (int i = 0; i<n;i++) {
            for (int j =0; j < n;j++) {
                if (i==j || j==n-i-1) {
                    if (grid[i][j] == 0) {
                        return false;
                    }
                } else {
                    if (grid[i][j] != 0) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};