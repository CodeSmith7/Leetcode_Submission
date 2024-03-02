class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l = 0;
        int h = nums.size() - 1;
        int k = nums.size() - 1;
        vector<int> ans(nums.size());
        while (k>=0) {
            int a = nums[l] * nums[l];
            int b = nums[h] * nums[h];

            if (a > b)  {
                ans[k] = a;
                l ++;   
            } else {
                ans[k] = b;
                h--;
            }
            k--;
        }
        return ans;
    }
};