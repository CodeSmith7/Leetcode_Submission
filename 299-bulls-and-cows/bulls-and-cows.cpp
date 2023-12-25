class Solution {
public:
    string getHint(string secret, string guess) {
    unordered_map<char,int> mp;
    
    string ans = "";
    for (int i = 0; i < secret.size();i++ ) {
          mp[secret[i]]++;
    }
    int x = 0;
    for (int i = 0; i< guess.size();i++ ) {
          if (secret[i] == guess[i]) {
              x++;
          }
    }

    int count = 0;
    for (int i = 0; i < guess.size(); i++ ) {
        if(mp[guess[i]] == 0) {
            count++;
        } else {
            mp[guess[i]]--;
        }
    }
    
    ans += std::to_string(x);
    ans += "A";
    ans += std::to_string(secret.size() - x - count);
    ans += "B";
    return ans;
}

};