/**
 * @author afmika
 * https://www.hackerrank.com/challenges/plus-minus/problem
 */
void plusMinus(vector<int> arr) {
    double pos = 0, neg = 0, zero = 0;
    double s = (double) arr.size ();
    for (int n : arr) {
        if (n < 0) neg++;
        if (n > 0) pos++;
        if (n == 0) zero++;        
    }
    cout << (pos / s) << "\n";
    cout << (neg / s) << "\n";
    cout << (zero / s) << "\n";
}
