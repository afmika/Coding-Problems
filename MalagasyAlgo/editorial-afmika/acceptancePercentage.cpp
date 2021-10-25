#include <bits/stdc++.h>
using namespace std;


int main() {
    int T, P;
    cin >> T >> P;
    int h[T];
    
    int s = 0;
    for (int t = 0; t < T; t++) {
        cin >> h[t];
        s += h[t];
    }
    
    for (int p = 0; p < P; p++) {
        int ds = 0;
        for (int t = 0; t < T; t++) {
            int v;
            cin >> v;
            ds += v * h[t];
        }
        ds *= 100;
        cout << (ds / s) << "\n";
    }
    
    return 0;
}
