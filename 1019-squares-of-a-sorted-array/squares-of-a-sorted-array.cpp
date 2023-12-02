class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l = 0;
        int h = nums.size()-1;
        int k = nums.size() -1;
        vector<int> ans(nums.size(),0);
        while (k >= 0) {  
            if (abs(nums[l])  > abs(nums[h])) {
                ans[k--] = nums[l] * nums[l++];
            } else {
                ans[k--] = nums[h] * nums[h--];
            }
        }
        return ans;
        
        
       
    }
};