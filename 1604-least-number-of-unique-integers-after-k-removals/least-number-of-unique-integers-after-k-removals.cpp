class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        vector <int> freq;

        for (auto x : arr) mp[x]++;

        for (auto [_,cnt] : mp) {
            freq.push_back(cnt);
        }
        sort (freq.begin(),freq.end());

        for (int i = 0; i<freq.size();i++) {
            k -= freq[i];
            if (k < 0) return freq.size()-i;
        }
        return 0;
    }
};