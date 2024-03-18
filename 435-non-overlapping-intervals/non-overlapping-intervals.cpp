class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //Approach 1 :
        
        //  sort (begin(intervals),end(intervals));

        // int i = 0,j = 1;
        // int count = 0;
    
        // while ( j < intervals.size()) {
           
        //     vector<int> currInterval = intervals[i];
        //     vector<int> nextInterval = intervals[j];

        //     int cs = currInterval[0];
        //     int ce = currInterval[1];
        //     int ns = nextInterval[0];
        //     int ne = nextInterval[1];


           
        //     if (ce <= ns) {//no overapping 
        //         i = j;
        //         j++;
        //     }
        //     else if  (ce <= ne) { // ovelapping
        //         j++;
        //         count++;
        //     }
        //     else if (ce > ne ) {
        //         i = j;
        //         count++;
        //         j++;
        //     }
        // }

        // return count;

        //Approach 2 :  

        sort (begin(intervals),end(intervals));

        int n = intervals.size();

        int count = 0;
        int i = 1;
        vector<int> lastInterval = intervals[0];

        while (i < n ) {
            int currEnd = intervals[i][1];
            int currStart = intervals[i][0];

            int lastEnd = lastInterval[1];

            if ( currStart >= lastEnd) {
                //safe 
                lastInterval = intervals[i];
                
            } else if (currEnd >= lastEnd ) {
                
                count++;
            } else if (currEnd < lastEnd) {
                lastInterval = intervals[i];
                count++;
            }
            i++;
        }
        return count;

    }
};