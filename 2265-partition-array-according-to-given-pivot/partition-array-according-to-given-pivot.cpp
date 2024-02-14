class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans(nums.size(),pivot);
        int l = 0, r = nums.size()-1;
        for (int i = 0 ;i < nums.size();i++) {
            if (nums[i] < pivot) ans[l++] = nums[i];
        }

        for (int i = nums.size() -1;i>=0;i--) {
            if (nums[i] > pivot) ans[r--] = nums[i];
            else if (nums[i] == pivot) {
                ans[l++] =  nums[i];
            }
        }
       
        return ans;
    }
};