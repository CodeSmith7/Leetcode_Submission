class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int ans =0 ;
        for (auto x: nums)
           ans += x;

         return  (nums.size() * (nums.size() +1))/2  - ans;
    }
};