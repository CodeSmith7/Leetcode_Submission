class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int ,int > mp;
        
        for (auto x: nums ) {
            mp[x]++;
        }
        int maxi = INT_MIN;
        int ans  = 0;
        for (auto &[a,b] : mp) {
             maxi = max(maxi,b);
        }
        cout << maxi << endl;
        for (auto &[a,b] : mp) {
            if (b == maxi) {
                cout << a << endl;
                ans += maxi;
            }
        }
        return ans;
    }
};