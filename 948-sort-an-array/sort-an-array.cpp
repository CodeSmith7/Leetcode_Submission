class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        unordered_map<int,int> mp;

        for (int &ele : nums) {
            mp[ele]++;
        }

        int minE = *min_element(begin(nums), end(nums));
        int maxE = *max_element(begin(nums), end(nums));

        int idx = 0;

        for (int i = minE; i <= maxE;i++) {
            
            while (mp[i] >0) {
                nums[idx] = i;
                idx++;
                mp[i]--;
            }
        }

        return nums;
    }
};