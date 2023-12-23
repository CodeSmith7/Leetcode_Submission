class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0;
        int i = 0; 
        int j = -1;

        int zero = 0;
        
        while ( i < nums.size()) {
            //aquire 
            if (nums[i] == 0) {
                zero++;
                i++;
            } else {
                i++;
            }

            //if invalid, release untill you are valid (RELEASE)
            while ( zero > k) {
                j++;
                if (nums[j] == 0) {
                    zero--;
                }
            }

            //consider 
            int sow = i-1-j;
            ans = max (ans,sow);
        }
        return ans;  
    }
};