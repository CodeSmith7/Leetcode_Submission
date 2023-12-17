class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sumi = 0; 
        for (int i = 0; i < n; i++) {
            sumi += mat[i][i] + mat[i][n-i-1];
        }
        if (n&1) sumi -= mat[n/2][n/2];
        return sumi; 
    }
};