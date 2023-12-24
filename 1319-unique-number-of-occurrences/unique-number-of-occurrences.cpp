class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // unordered_map<int,int> mp;
        // for (auto x: arr) {
        //     mp[x]++;
        // }
        // unordered_set<int> st;
        // for (auto x : mp) {
        //     int e = x.second;
        //     if (st.find(e) != st.end()) {
        //         return false;
        //     }
        //     st.insert(e);
        // }
        // return true;


        unordered_map<int,int> mp;
        for (auto x: arr) {
            mp[x]++;
        }
        unordered_set<int> st;
        for (auto x : mp) {
            st.insert(x.second);
        }
        return (mp.size() == st.size());
    }
};