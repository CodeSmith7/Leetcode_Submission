class Solution {
public:
    string removeKdigits(string num, int k) {
        string result = "";

        int n = num.length();

        for (int i = 0; i < n;i++) {

            while (result.size() > 0 && result.back() > num[i] && k > 0) {
                result.pop_back();
                k--;
            }

            if (result.size() > 0 || num[i] != '0' ) {
                result.push_back(num[i]);  //to avoid the case when we have preceding zeroes

             }
        }


        while ( k > 0 && result != "") {
            result.pop_back();
            k--;
        }

        if (result == "" ) {
            return "0";
        }

        return result;
    }
};