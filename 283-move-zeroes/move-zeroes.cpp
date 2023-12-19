class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // int idx = 0;
        // for (int i = 0;i<nums.size();i++  ) {
        //     if (nums[i] != 0) {
        //         swap (nums[idx],nums[i]);
        //         idx++;
        //     }
        // }

        //good method 
        int i = 0;
        int j = 0;
        
        //0  to j-1 -> non zero
        //j to i-1 -> zero
        //i to end ->unknown

        while(i < nums.size()) {
            if (nums[i] == 0) {
                i++;
            } else  {
                swap(nums[i++],nums[j++]);
            }
        }
    }
};