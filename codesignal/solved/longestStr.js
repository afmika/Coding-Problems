/*
Given an array of strings, return another array containing all of its longest strings.

Example

For inputArray = ["aba", "aa", "ad", "vcd", "aba"], the output should be
allLongestStrings(inputArray) = ["aba", "vcd", "aba"].
*/

function allLongestStrings(inputArray) {
    let max = -1;
    for (let i = 0; i < inputArray.length; i++) {
        if (max < inputArray[i].length ) {
            max = inputArray[i].length;
        }
    }
    return inputArray.filter( str => str.length == max);
}

console.log( allLongestStrings(["aba", "aa", "ad", "vcd", "aba"]) );