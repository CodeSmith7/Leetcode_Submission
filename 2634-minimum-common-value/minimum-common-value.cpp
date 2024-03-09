class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st(nums2.begin(),nums2.end());

        for (int &num : nums1) {
            if (st.find(num) != st.end()) {
                return num;
            }
        }

        return -1;
    }
};