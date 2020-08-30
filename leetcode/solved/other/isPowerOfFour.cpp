class Solution {
public:
    bool isInteger(double x) {
        return floor(x) == x;
    }
    bool isPowerOfFour(int num) {
        if ( num <= 0 ) return false;
        double exponent = log( num ) / log(4);
        if ( ! isInteger( exponent ) ) {
            return false;
        }
        return true;        
    }
};
