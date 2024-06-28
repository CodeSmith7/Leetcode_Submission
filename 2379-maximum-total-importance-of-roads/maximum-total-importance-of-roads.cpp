class Solution {
public:

    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degree(n,0);

        for (auto &vec : roads) {
            int u = vec[0];
            int v = vec[1];

            degree[u]++;
            degree[v]++;
        }

        sort(begin(degree),end(degree));

        long long sum = 0;
        long long value = 1;

        for (int i = 0; i < n;i++) {
            sum += value * degree[i];
            value++;
        } 

        return sum;

    }
};