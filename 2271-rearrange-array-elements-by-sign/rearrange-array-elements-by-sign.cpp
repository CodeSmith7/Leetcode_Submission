class Solution {
public:
   vector<int> rearrangeArray(vector<int>& nums) {
        // vector<int> pos, neg;
        // for (int num : nums) {
        //     if (num > 0) {
        //         pos.push_back(num);
        //     } else {
        //         neg.push_back(num);
        //     }
        // }

        // vector<int> ans;
        // int i = 0, j = 0;
        // while (i < pos.size() && j < neg.size()) {
        //     ans.push_back(pos[i++]);
        //     ans.push_back(neg[j++]);
        // }
        // return ans;

        vector<int> ans(nums.size(),0);
        int pos = 0;
        int neg = 1;
        for( int i = 0;i< nums.size();i++) {
            if (nums[i] > 0) {
                ans[pos] = nums[i];
                pos += 2;
            } else {
                ans[neg] = nums[i];
                neg += 2;
            }
        }
        return ans;
    }

};