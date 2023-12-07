class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result(candies.size(),false);

        int maxi = candies[0];
        for (auto x : candies) {
            maxi = max(x,maxi);
        }
        for (int i = 0; i<candies.size() ;i++) {
            if ((candies[i] + extraCandies) >= maxi) {
                result[i] = true;
            } 
        }

        return result;
        
    }
};