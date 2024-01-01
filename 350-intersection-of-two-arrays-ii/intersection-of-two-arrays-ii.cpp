class Solution {
public:
 vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int,int> mp;
    vector<int> ans;
    for (auto x  : nums1) {
        mp[x]++;
    }

    for (auto x : nums2) {
        auto it = mp.find(x);
        if (it != mp.end() && it->second > 0) {
            ans.push_back(x);
            it->second--; 
        }
    }
    return ans;
}

};