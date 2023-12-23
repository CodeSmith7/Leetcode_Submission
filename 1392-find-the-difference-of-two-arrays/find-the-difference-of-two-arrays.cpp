class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(),nums1.end());
        unordered_set<int> s2(nums2.begin(),nums2.end());

        for (auto x: nums2) {
            if (s1.find(x) != s1.end())
              s1.erase(x);
        }
        for (auto x: nums1) {
            if (s2.find(x) != s2.end()) {
               s2.erase(x); 
            }
        }

        return {vector<int>(s1.begin(),s1.end()), vector<int>(s2.begin(),s2.end())};
        
        
    }
};