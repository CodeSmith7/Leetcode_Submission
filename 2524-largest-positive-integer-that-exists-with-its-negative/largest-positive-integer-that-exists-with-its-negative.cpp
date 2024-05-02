class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int arr[2001] = {0};
        int ans = -1;
        
        int result = -1;

        for (int i = 0;i < nums.size();i++) {
            int counter = -nums[i] + 1000;
            if (arr[counter] == 1) {
               result = abs(nums[i]);
            } else if (arr[counter] == 0) {
                arr[nums[i] + 1000] = 1;
            }
            ans = max(ans,result);
        }
        return ans;
    }
};