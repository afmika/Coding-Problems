/*
Consider integer numbers from 0 to n - 1 written down along the circle in such a way that the distance between any two neighboring numbers is equal (note that 0 and n - 1 are neighboring, too).

Given n and firstNumber, find the number which is written in the radially opposite position to firstNumber.

Example

For n = 10 and firstNumber = 2, the output should be
circleOfNumbers(n, firstNumber) = 7.

Ex : n = 6, firstNumber = 1
output : 4
   0  1
5  *  *  2
 *      *
 4 *  * 3
  
*/

function circleOfNumbers(n, firstNumber) {
    return ( firstNumber + n / 2 ) % n;
}