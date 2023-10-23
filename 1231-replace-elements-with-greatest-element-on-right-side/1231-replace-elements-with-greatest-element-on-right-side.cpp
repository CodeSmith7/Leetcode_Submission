class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> ans(arr.size(),-1);
        int cl = arr[arr.size() - 1];
       
        for (int i = arr.size() -2; i>=0;i--) {
            cl = max (cl,arr[i+1]);
            ans[i] = cl;
         }
        
        return ans;
    }
};