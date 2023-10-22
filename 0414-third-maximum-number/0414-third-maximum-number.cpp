class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
        priority_queue<int,vector<int>,greater<int>> pq;
        unordered_set<int> st;
        for(auto x: nums) {
            st.insert(x);
        }
        if (st.size() < 3) {
            return *max_element(st.begin(),st.end());
        }
        for (auto x: st) {
            pq.push(x);
            if(pq.size() > 3) {
                pq.pop();
            }
        } 
        return pq.top();
    }
};