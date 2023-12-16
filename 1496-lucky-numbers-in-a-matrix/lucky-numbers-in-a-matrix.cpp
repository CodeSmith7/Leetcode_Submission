class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> ans;

    for (int i = 0; i < n; i++) {
        int mini = INT_MAX, idx;
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] < mini) {
                mini = matrix[i][j];
                idx = j;
            }
        } 

        int maxi = INT_MIN;
        for (int j = 0; j < n; j++) {
            if (matrix[j][idx] > maxi) {
                maxi = matrix[j][idx];
            }
        }

        if (maxi == mini) {
            ans.push_back(mini);
        }
    }  

    return ans;
  }

};