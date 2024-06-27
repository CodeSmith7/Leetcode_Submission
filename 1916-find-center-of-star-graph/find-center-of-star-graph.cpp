class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> mp;

        for (auto &vec : edges) {
            int u = vec[0];
            int v = vec[1];

            mp[u]++;
            mp[v]++;
        }

        for (auto &it: mp) {
            if (it.second == edges.size()) {
                return it.first;
            }
        }
        return -1;
    }
};