class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int,string> mp;
        int n = heights.size();

        for (int i = 0; i < n;i++) {
            int height = heights[i];
            string name = names[i];
            mp[height] = name;
        }

        vector<string> ans;

        for(auto &[a,b] : mp) {
            ans.push_back(b);
        }
        reverse(ans.begin(),ans.end());
        
        return ans;        
    }
};