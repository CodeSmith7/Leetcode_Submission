class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 1;
        int r = num;
        if (num == 0 || num == 1) return true;
        while ( l <= r) {
            int  mid = (l + (r -l)/2);
            if (mid == num/mid && num %mid == 0) return true;
            else if ( mid < num/mid ) l = mid + 1;
            else r = mid -1;
        }
        return false;
    }
};