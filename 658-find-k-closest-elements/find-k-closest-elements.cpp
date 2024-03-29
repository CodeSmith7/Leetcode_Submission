class Solution {
public:
    static bool cmp(pair<int,int> p1,pair<int,int> p2) {
        if (p1.second == p2.second) {
            return p1.first < p2.first;
        }
        return p1.second < p2.second;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int,int>> v;
        vector<int> ans;

        for(auto y : arr) {
            v.push_back( {y, abs(y-x)} );
        }

        sort(v.begin(),v.end(),cmp);

        for (auto x : v) {
            if (ans.size() != k) {
                ans.push_back(x.first);
            }
        }
        sort (ans.begin(),ans.end());

        return ans;
         
    }
};