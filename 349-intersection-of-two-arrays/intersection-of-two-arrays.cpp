class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st;
        unordered_map<int,int> mp;
        for (auto x: nums1 ) {
            mp[x]++;
        }
        for (auto x : nums2) {
            if (mp.find(x) != mp.end()) {
                st.insert(x);
            }
        }
        return vector<int>(st.begin(),st.end());
        
    }
};