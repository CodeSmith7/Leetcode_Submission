class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        long long  sum = 0;
        for (auto x: nums) {
            sum += x;
        }
        long long lsum = 0;
        for (int i  = 0;i< nums.size();i++) {
            sum -= nums[i];
            if (lsum == sum){
                return i;
            } 
            lsum += nums[i];
        }
        return -1;
    }
};