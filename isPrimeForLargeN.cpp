#include <bits/stdc++.h>

using namespace std;

double Li (double value) {
    double dx = 0.1, s = 0.;
    for (double x = 2; x <= value; x += dx) {
        s += dx / log(x);
    }
    return s;
}

bool isPrime (double value) {
    // is there any prime between value + 1 and value - 1 ?
    // if yes then value must be THAT prime
    // Note : pi(x) - Li(x) = O(something)
    // this will sometimes give the wrong result but in most case it should be ok
    int count = Li(value + 1) - Li(value - 1);
    cout << "Count " << count << "\n";
    return count > 0;
}

int eq (int a, int b, int n) {
    return n*n + a*n + b;
}

int main() {
    cout << Li(4);
    // for (int i = 41; i < 77; i++) {
    //     if (isPrime (i)) {
    //         cout << i << "\n";
    //     }
    // }
    return 0; 
}
