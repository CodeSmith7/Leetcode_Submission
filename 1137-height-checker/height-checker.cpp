class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> actualOrder(begin(heights),end(heights));
        sort(begin(actualOrder),end(actualOrder));

        int count = 0;
        for (int i = 0;i < heights.size();i++) {
            if (heights[i] != actualOrder[i]) {
                count++;
            }
        }
        return count;
    }
};