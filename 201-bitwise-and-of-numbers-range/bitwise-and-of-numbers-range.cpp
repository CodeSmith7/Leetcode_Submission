class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
       int shift = 0;
       while (left < right ) {
          //common prefix identification  
           left >>= 1;      //right shift the left and right until it become equal 
           right >>= 1;
           shift++;
       }       
       if (left ==  0) return 0; 
       return left << shift;//left shit i.e. add zero from starting at common prefix
    }
};