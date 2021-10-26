/**
 * @author afmika
 * Problem : Acceptance percentage
 * AlgoMada Devfest Rookies Contest solution
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    // T : the weights of the test sets
    // P : total number of the code submissions
    int T, P;
	
    cin >> T >> P;
    int weights[T];
    
    // Fetch the weights
    // process the total sum at the same time
    int s = 0;
    for (int t = 0; t < T; t++) {
        cin >> weights[t];
        s += weights[t];
    }
    
    // Complexity : O(P*T) in time / O(T) in space
    
    for (int p = 0; p < P; p++) {
        int ds = 0;
        for (int t = 0; t < T; t++) {
            int v;
            cin >> v;
            // v is either a "0" or a "1"
            // the following line is equivalent to 
            // if (v == 1)
            //   ds += weights[t];
            // else
            //    /* do nothing */;

            ds += v * weights[t];
        }
        // if     s ---> 100
        // then  ds ---> ?
        // answer = floor(ds * 100 / s)
        ds *= 100;
        cout << (ds / s) << "\n";
    }
    
    return 0;
}
