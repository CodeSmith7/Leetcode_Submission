class Solution {
public:
    string intToRoman(int num) {
    //      string roman[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    //     int value[]  =  {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    //     string  ans = "";
    //     for (int i = 0;i<13;i++) {
    //         while (num >= value[i]) {
    //             ans += roman[i];
    //             num -= value[i];
    //         }
    //     }
    //     return ans;
    
      string ans = ""; 

      solve (ans,'*','M','*',num/1000);
      num = num %1000;     
     
      solve (ans ,'M','C','D',num/100);
      num = num %100;

      solve (ans, 'C','X','L',num/10);
      num = num %10;

      solve (ans, 'X' ,'I' , 'V',num);
      
      return ans;
     }

     void solve (string &sb, char major, char minor, char mid, int val)  {
         if (val <= 3) {
             for (int i = 0;i < val;i++) {
                  sb += minor;
             }
         } else if ( val == 4) {
             sb += minor;
             sb += mid;
         } else if (val == 5) {
             sb += mid;
         } else if (val <= 8) {
             sb += mid;
             for (int i =0 ;i < val - 5;i++) {
                 sb += minor;
             }
         } else if (val == 9) {
             sb += minor;
             sb += major;
         }
     }



};