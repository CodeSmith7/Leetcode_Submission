class Solution {
public:
    int longestSubsequence(vector<int>& arr, int c) {
        unordered_map<int,int> mp;
        int ans = 1;

        for (int i = 0; i< arr.size();i++) {
            int sol = mp[arr[i] - c] + 1;
            mp[arr[i]] = sol;

            if (ans < sol){
                ans = sol;
            }
        }
        return ans;
    }
};