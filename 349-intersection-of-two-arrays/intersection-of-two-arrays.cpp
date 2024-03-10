class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // unordered_set<int> st;
        // unordered_map<int,int> mp;
        // for (auto x: nums1 ) {
        //     mp[x]++;
        // }
        // for (auto x : nums2) {
        //     if (mp.find(x) != mp.end()) {
        //         st.insert(x);
        //     }
        // }
        // return vector<int>(st.begin(),st.end());

        //approach 1 : 

        unordered_set<int> st1(nums1.begin(),nums1.end());

        unordered_set<int> st2;

        for (int &num : nums2) {
            if (st1.find(num) != st1.end()) {
                st2.insert(num);
            }
        }

        vector <int> res(begin(st2),end(st2));
        return res;
        
    }
};