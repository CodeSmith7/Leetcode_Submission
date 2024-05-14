class Solution {
public:
    vector<vector<int>> directions{{-1,0},{1,0},{0,-1},{0,1}};
    int DFS(vector<vector<int>>& grid,int i,int j, int m , int n) {
        
        if ( i < 0 || i >= m || j < 0 || j >= n  || grid[i][j] == 0) {
            return 0;
        }

        int originalGold = grid[i][j];
        grid[i][j] = 0;

        int maxGold = 0;

        //up down left right 

        for (vector<int>& dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            maxGold = max(maxGold, DFS(grid,new_i,new_j,m,n));

        }

        grid[i][j] = originalGold;


        return maxGold + originalGold;

    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int maxGold = 0;

        for (int i = 0; i<m;i++) {
            for (int j = 0; j < n;j++) {
                
                if (grid[i][j] != 0) {
                    maxGold = max (maxGold, DFS(grid,i,j,m,n))
                    ;
                }
            }
        }

        return maxGold;
    }
};