class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {

       long long sum = 0;
       
       for (int &ele : chalk) {
        sum += ele;
       }

       while (k >= sum) {
        k -= sum;
       }

       for (int i = 0; i < chalk.size();i++) {
            
            if (chalk[i] > k) {
                return i;
            } else {
                k -= chalk[i]; 
            }
        }

        return 0;
        
    }
};