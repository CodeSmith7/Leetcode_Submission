class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0;
        int i = 0;
        int j = -1;
        int count = 0;
        while ( i < nums.size()) {
            // acquire 
            if (nums[i] == 1) {
                i++;
            }  else {
                i++;
                count++;
            }

            //release 
            while(count > 1 && j < i) {
                j++;
                if (nums[j] == 0) {
                    count--;
                }
            } 

            //consider 
            ans = max(ans,i-j-1);
        }
        return ans-1;
    }
};