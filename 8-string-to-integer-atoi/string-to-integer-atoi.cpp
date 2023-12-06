class Solution {
public:
    int myAtoi(string s) {
      // return atoi(s.c_str());   
      // return stoi(s); 
      //to_string() used to convert number to string 
      
      int num =0,i=0,sign =1;
      //ignoring the leading spaces 
      while(s[i] ==' ')
        i++;   
      // checking the sign of the given number 
       
       if (i<s.size() && s[i]=='-' || s[i] == '+'){
          sign = s[i] == '+' ? 1:-1;
          i++;
        }

        while (i<s.size() && isdigit(s[i])){
            //checking the overflow condition 
            if (num > INT_MAX/10 || (num == INT_MAX/10 && s[i] >'7')){
                return sign == -1? INT_MIN :INT_MAX;
            }
          //  converting the digit to the number equivalent 
            num = num*10 + (s[i] -'0');
            i++;
        }  
  
        //returning the number acquired with their proper sign 
        return num * sign;
    }
};