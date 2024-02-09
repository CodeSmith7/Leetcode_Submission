class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort (nums.begin(),nums.end());

        vector<int> dp(n,1);
        vector<int>  hash(n,1);

        for (int i = 0; i< nums.size();i++) {
            hash[i] = i;
             for (int j = 0; j < i;j++) {

                 if (nums[i] % nums[j] == 0 && 1 + dp[j] > dp[i]) {
                     dp[i] = 1+dp[j];
                     hash[i] = j;
                 }
             }
        }
        int ans = -1;
        int last = -1; 

        for (int i = 0;i < n;i++) {
            if (dp[i] > ans) {
                ans = dp[i];
                last = i;
            }
        }

        vector<int> temp;
        temp.push_back(nums[last]);

        while (hash[last] != last) {
            last = hash[last];
            temp.push_back(nums[last]);
        }
        reverse(temp.begin(),temp.end());
        return temp;

    }
};