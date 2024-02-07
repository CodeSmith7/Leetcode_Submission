class Solution {
public:
    string frequencySort(string s) {
        map<char,int> mp;
        multimap<int,char> mp1;
        string ans = "";
        
        for (auto& x: s) {
            mp[x]++;
        }
        for (auto& [k,v] : mp) {
            mp1.insert({v,k});
        }


        for (auto x : mp1) {
            cout << x.first << " " << x.second << endl;
        }
        
        for (auto it = mp1.rbegin(); it != mp1.rend();++it) {
            int count = it->first;
            while (count--) {
              ans += it->second;
            }
         
        }
      return ans;
    }
};