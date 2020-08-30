/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function(digits) {
    let res = [];
    let r = 0;
    for(let i = digits.length - 1; i >= 0; i--) {
        let s = r + digits[i] + (i == digits.length - 1 ? 1 : 0);
        if( s >= 10) {
            r = 1;
            res.push(s - 10);
        } else {
			r = 0;
            res.push(s);
        }
    }
	if( r > 0) {
		res.push(r);
	}
	return res.reverse();
};

console.log( plusOne([1, 7,9,9]) )