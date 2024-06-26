class Solution {
public:
    vector<string> getToken(string version) {
        stringstream ss(version);
        string token = "";
        vector<string> vec;
        while (getline(ss,token,'.') ) {
           vec.push_back(token);
        } 
        return vec;
    }

    int compareVersion(string version1, string version2) {
        vector<string> v1 = getToken(version1);
        vector<string> v2 = getToken(version2);

        int m = v1.size();
        int n = v2.size();
        int i = 0;

        while ( i < m || i < n) {
            int a = i < m ? stoi(v1[i]) : 0;
            int b = i < n ? stoi(v2[i]) : 0;

            if (a < b) {
                return -1;
            } else if (a > b) {
                return 1;
            } else {
                i++;
            }
        }
        return 0;
    }
};