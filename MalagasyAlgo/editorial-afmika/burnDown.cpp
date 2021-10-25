#include <bits/stdc++.h>
using namespace std;


int main() {
    int P, D;
    cin >> P >> D;
    int perDay = P / D;
    
    int point[2][D];
    for (int i = 0; i < D; i++) {
        cin >> point[0][i];
        if (i + 1 < D)
            point[1][i] = perDay;
    }
    point[1][D - 1] = P - (D - 1) * perDay;
    
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
