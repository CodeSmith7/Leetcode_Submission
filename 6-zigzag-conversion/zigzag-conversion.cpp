class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        string ans;

        for (int i = 0; i < numRows; i++  ) {
          
            int idx = i;
            int deltaSouth = 2 * (numRows -1 -i);
            int deltaNorth = 2 * i;
            bool goingSouth = true;

            while (idx < s.size() ) {
                ans += s[idx];

                if (i == 0) {
                    idx += deltaSouth;
                } else if (i == numRows -1) {
                    idx += deltaNorth;
                } else {
                  
                    if (goingSouth) {
                        idx += deltaSouth; 
                    } else {
                        idx += deltaNorth;
                    }
                    goingSouth = !goingSouth;

                }
            }
        }

        return ans;

    }
};