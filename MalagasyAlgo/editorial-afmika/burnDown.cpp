/**
 * @author afmika
 * Problem : Burndown
 * AlgoMada Devfest Rookies Contest solution
 */

#include <bits/stdc++.h>
using namespace std;


int main() {
    int P, D;
    cin >> P >> D;
    // by default, we want to distribute the points evenly amoung D days 
    int perDay = P / D;
    
    int point[2][D];
    for (int i = 0; i < D; i++) {
        cin >> point[0][i];       // task points the team completed for this day
        if (i + 1 < D)
            point[1][i] = perDay; // ideal task points
    }
    // points for the last day := total points - (*ideal* total points of the previous days)
    point[1][D - 1] = P - (D - 1) * perDay; // ideal task points for the last day
    
    // Complexity : O(D) time / O(D) space
    int ideal = 0;
    int done = 0;
    for (int i = 0; i < D; i++) {
        done += point[0][i];
        ideal += point[1][i];
        if (ideal <= done)
            cout << (i + 1) << " ";
    }
    
    return 0;
}
