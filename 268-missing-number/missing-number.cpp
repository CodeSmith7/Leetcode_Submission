//Approach 1: using math
// class Solution {
// public:

//     int missingNumber(vector<int>& nums) {

//         int ans =  (nums.size() * (nums.size() +1))/2 ;
//         for (auto x: nums)
//            ans -= x;

//          return ans;
//     }
// };


//Approach 2 : using XOR
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = nums.size();
        for(int i = 0; i<nums.size(); i++) {
            sum ^= i;
            sum ^= nums[i];
        }
        return sum;
    }
};