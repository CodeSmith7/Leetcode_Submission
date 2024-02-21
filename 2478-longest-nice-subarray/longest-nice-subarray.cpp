class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int u = 0, j = 0,ans = 0;

        for (int i = 0;i < nums.size(); ++i) {
            while ((u & nums[i]) != 0) {
                u ^= nums[j++];
            }
            u |= nums[i];
            ans = max(ans,i-j+1);
        }
        return ans;
    }
};