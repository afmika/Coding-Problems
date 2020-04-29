/*
Given an array of integers, find the pair of adjacent elements that has the largest product and return that product.

Example

For inputArray = [3, 6, -2, -5, 7, 3], the output should be
adjacentElementsProduct(inputArray) = 21.

7 and 3 produce the largest product.
*/
function adjacentElementsProduct(inputArray) {
    let prod = -Infinity;
    for(let i = 0, j = 1; j < inputArray.length; i++, j++) {
        let p = inputArray[i] * inputArray[j];
        if (p > prod) {
            prod = p;
        }
    }
    return prod;
}
