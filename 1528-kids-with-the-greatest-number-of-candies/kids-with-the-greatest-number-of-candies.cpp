class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result(candies.size());

        int maxi = candies[0];
        for (auto x : candies) {
            maxi = max(x,maxi);
        }
        for (int i = 0; i<candies.size() ;i++) {
             result[i] = (candies[i] + extraCandies) >= maxi; 
        }

        return result;
        
    }
};