/*
Given array of integers, check whether each integer, that occurs in it, is contained there the same number of times as any other integer from the given array.

Example

    For inputArray = [1, 2, 2, 1], the output should be
    checkEqualFrequency(inputArray) = true;
    For inputArray = [1, 2, 2, 3, 1, 3, 1, 3], the output should be
    checkEqualFrequency(inputArray) = false.

Input/Output

    [execution time limit] 0.5 seconds (cpp)

    [input] array.integer inputArray

    Guaranteed constraints:
    1 ≤ inputArray.length ≤ 5 · 104,
    1 ≤ inputArray[i] ≤ 4 · 108.

    [output] boolean
*/
bool checkEqualFrequency(std::vector<int> inputArray) {
    map<int, int> m;
    for (int i = 0; i < inputArray.size(); i++) {
        if ( m.find( inputArray[i] ) == m.end()) {
            m[ inputArray[i] ] = 1;
        } else {
            m[ inputArray[i] ]++;
        }
    }
    map<int, int>::iterator it;
    int cur = -1;
    for (it = m.begin(); it != m.end(); it++) {
        int key = it->first;
        int val = it->second;
        if (cur < 0 ) {
            cur = val;
        } else {
            if ( cur != val ) {
                return false;
            }
        }
    }
    return true;
}
