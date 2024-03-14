class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> mp;

        int result = 0;
        int cumSum = 0;

        mp.insert({0,1});
        

        for (int i = 0; i < nums.size();i++) {
            cumSum += nums[i];

            if (mp.find(cumSum - goal) != mp.end()) {
                result += mp[cumSum - goal];
            }

            mp[cumSum]++;
        }

        return result;
    }
};