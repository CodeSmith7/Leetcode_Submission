class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int l = 0;
        int r = nums.size()-1;
        int ans = 0;
        sort (nums.begin(),nums.end());
        while ( l < r) {
            if (nums[l] == k - nums[r]) {
                l++;
                r--;
                ans++;
            } else if ( nums[l] + nums[r] < k) {
                l++;
            } else {
                r--;
            }
        }
        return ans;
    }
};