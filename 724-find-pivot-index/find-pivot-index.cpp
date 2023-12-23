class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // long long  sum = 0;
        // for (auto x: nums) {
        //     sum += x;
        // }
        // long long lsum = 0;
        // for (int i  = 0;i< nums.size();i++) {
        //     sum -= nums[i];
        //     if (lsum == sum){
        //         return i;
        //     } 
        //     lsum += nums[i];
        // }
        // return -1;



        //second method using prefixx sum 

        int* pre =new int[nums.size()];
        int sum = nums[0];
        pre[0] = 0;
        for (int i = 1; i < nums.size();i++) {
            sum += nums[i];
            pre[i] = pre[i-1] + nums[i-1];
        }

        for (int i = 0; i < nums.size();i++) {
            if (pre[i] == sum - pre[i] -nums[i]) {
                return i;
            }
        }
        return -1;
    }
};