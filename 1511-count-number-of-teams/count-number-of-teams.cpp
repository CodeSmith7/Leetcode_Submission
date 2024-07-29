class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        
        int teams = 0;

        for (int j = 1; j < n-1; j++) {
            int smallerLeft = 0;
            int smallerRight = 0;
            int greaterRight = 0;
            int greaterLeft = 0;

            //exploring the left 
            for(int l = 0; l < j;l++) {
                
                if (rating[l] < rating[j]) {
                    smallerLeft++;
                } else if (rating[l] > rating[j]) {
                    greaterLeft++;
                }   
            }

            //eploring the right 
            for (int r = j +1; r < n;r++) {

                if (rating[r] < rating[j]) {
                    smallerRight++;
                } else if (rating[r] > rating[j]) {
                    greaterRight++;
                }
            }

            teams += (smallerLeft * greaterRight)  + (greaterLeft * smallerRight);
        }

        return teams;
    }
};