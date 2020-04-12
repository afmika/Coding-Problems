/**
 * @param {number} x
 * @return {number}
 */
var mySqrt = function(x) {
    if(x == 0 || x == 1)
        return x;
    let q = 1;
    while(true) {
        let p = q * q;
        if(p == x)
            return q;
        if(p > x)
            return q-1;
        q++;
    }
};

console.log( mySqrt(36) );
console.log( mySqrt(38) );
console.log( mySqrt(7) );