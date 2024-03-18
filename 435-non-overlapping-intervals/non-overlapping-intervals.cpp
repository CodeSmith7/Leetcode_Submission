class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
         sort (begin(intervals),end(intervals));

        int i = 0,j = 1;
        int count = 0;
    
        while ( j < intervals.size()) {
           
            vector<int> currInterval = intervals[i];
            vector<int> nextInterval = intervals[j];

            int cs = currInterval[0];
            int ce = currInterval[1];
            int ns = nextInterval[0];
            int ne = nextInterval[1];


           
            if (ce <= ns) {//no overapping 
                i = j;
                j++;
            }
            else if  (ce <= ne) { // ovelapping
                j++;
                count++;
            }
            else if (ce > ne ) {
                i = j;
                count++;
                j++;
            }
        }

        return count;
    }
};