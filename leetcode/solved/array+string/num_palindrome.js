/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    if(x < 0) 
        return false;
    x = x+'';
    const middle = x.length / 2;
    for(let i = 0; i < middle; i++) {
        const right = x[x.length - 1 - i];
        const left = x[i];
        if(right != left) {
            return false;
        }
    }
    return true;
};
console.log( isPalindrome(12343021) )