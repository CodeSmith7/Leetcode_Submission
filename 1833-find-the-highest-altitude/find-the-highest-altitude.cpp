class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int height = 0;
        int ans = 0;

        for (auto x: gain) {
            height += x;
            ans = max (height,ans);
        }
        return ans;
    }
};