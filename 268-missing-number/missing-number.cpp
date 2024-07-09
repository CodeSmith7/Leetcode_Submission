class Solution {
public:

    int missingNumber(vector<int>& nums) {

        int ans =  (nums.size() * (nums.size() +1))/2 ;
        for (auto x: nums)
           ans -= x;

         return ans;
    }



};