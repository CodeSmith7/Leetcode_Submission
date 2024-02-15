class Solution {
public:
   
    
    int triangleNumber(vector<int>& nums) {
        sort ( nums.begin(),nums.end());

        int n = nums.size();
        int count = 0;

        for(int i = n -1; i >= 1;i--) {
            int l = 0;
            int r = i-1;

            while (l < r) {
                if (nums[l] + nums[r] > nums[i] ) {
                    count += r - l; //count the all possoib8e triangle that can used in the range as all other values sum is definitely biggger than the given  sum.
                    r--;
                }
                else{
                    l++;
                }
            }
        }
        return count;  
    }
};