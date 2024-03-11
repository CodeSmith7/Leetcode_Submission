class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        
        auto cmp = [&k](vector<int> &v1,vector<int> &v2) {
                if(v1[k] > v2[k]) return true;
                else return false;
        };
        
        sort (score.begin(),score.end(),cmp);
        return score;
    }
};