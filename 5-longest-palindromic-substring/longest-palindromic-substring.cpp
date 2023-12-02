class Solution {
public:
    string longestPalindrome(string s) {
        string  ans = "";
         
       //testing odd palindrome 
      for (int ax = 0; ax < s.size();ax++) { 
            int orb = 1;
            int len = 1;
 
            while (ax - orb >= 0 && ax+orb < s.size() ) {

                 if (s[ax-orb] == s[ax+orb]  ) {
                     orb++;
                     len += 2;
                 } else {
                     break;
                 }

            }
            if (len > ans.size()) {
                int si = ax - len /2;
                ans = s.substr(si,len);
            }


        } 

        //testing even  palindrome 
      for (int ax = 0; ax < s.size() - 1 ;ax++) { 
            int orb = 1;
            int len = 0;
 
            while (ax - orb + 1 >= 0 && ax+orb < s.size() ) {

                 if (s[ax-orb +1] == s[ax+orb]  ) {
                     orb++;
                     len += 2;
                 } else {
                     break;
                 }

            }
            if (len > ans.size()) {
                int si = ax - len /2  +  1;
                ans = s.substr(si,len);
            }


        } 
        return ans;
    }
};