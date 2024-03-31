class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int n = nums.size();

        long long prod = 1;
        long long ans = 0;

        if (k <= 1) {
            return 0;
        }

        while ( j < n) {
            prod *= nums[j];

            while (prod >= k) {
                prod = prod / nums[i];
                i++;
            }
            ans += j-i+1;
            j++;
        }

        return ans;
    }
};