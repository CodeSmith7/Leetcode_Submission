class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        for (int &ele: nums) {
           ans ^= ele;
        }
        ans = ans ^ k;
        return __builtin_popcount(ans);
    }
};