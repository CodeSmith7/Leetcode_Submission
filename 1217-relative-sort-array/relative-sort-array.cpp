class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> mp;
        for (int &ele : arr1 ) {
            mp[ele]++;
        } 
        vector<int> ans;

        for (int i = 0; i < arr2.size();i++) {
            int freq = mp[arr2[i]];
            while (freq--) {
                ans.push_back(arr2[i]);
            }
            mp.erase(arr2[i]);
        }

        for (auto &[a,b] : mp) {
            int freq = b;
            while (freq--) {
                ans.push_back(a);
            }
        }
        return ans;

    }
};