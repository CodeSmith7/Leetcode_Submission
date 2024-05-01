class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        char maxNumber = ' ';

        for (int i = 2; i <n; i++) {
            if (num[i] == num[i-1] && num[i] == num[i-2] ) {
                maxNumber = max (maxNumber , num[i]);
            }
        }

        if (maxNumber == ' ') {
            return "";
        }
         
        return string(3,maxNumber);
        
    }
};