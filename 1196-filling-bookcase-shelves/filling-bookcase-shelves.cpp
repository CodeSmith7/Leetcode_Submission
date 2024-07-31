class Solution {
public:
    int n;
    int WIDTH;
    int dp[1001][1001];
    int solve (vector<vector<int>>& books,int i, int remainW,const int &maxH) {
        if (i >= n) {
            return maxH;
        }

        if (dp[i][remainW] != -1) {
            return dp[i][remainW];
        }

        int bookW = books[i][0];
        int bookH = books[i][1];

        int keep = INT_MAX;
        int skip = INT_MAX;

        //keep'
        if(bookW <= remainW) { //let's keep it here
            keep = solve(books, i+1, remainW - bookW, max(maxH, bookH));
        }

        //skip ansd place the book in the next shelf
        skip = maxH + solve (books, i+1, WIDTH - bookW, bookH);

        return dp[i][remainW] = min(skip,keep);
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        n = books.size();
        memset(dp,-1,sizeof(dp));
        WIDTH = shelfWidth;
        int remainW = WIDTH;
        return solve (books,0,remainW,0);
    }
};