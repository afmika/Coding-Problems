#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int manh (vector<int> d, vector<int> cur) {
    int dy = d[0], dx = d[1];
    int cy = cur[0], cx = cur[1];
    return abs(dx - cx) + abs(dy - cy);
}

int main() {
    int nrow, ncol;
    cin >> nrow >> ncol;
    
    vector<int> depart;
    char grid[nrow][ncol];
    for (int y = 0; y < nrow; y++) {
        for (int x = 0; x < ncol; x++) {
            char c;
            cin >> c;
            if (c == 'D')
                depart = {y, x};
            grid[y][x] = c;
        }
    }

    for (int y = 0; y < nrow; y++) {
        for (int x = 0; x < ncol; x++) {
            if (grid[y][x] == '#')
                cout << -1;
            else
                cout << manh(depart, {y, x});
            if (x + 1 == ncol)
                cout << "\n";
            else
                cout << " ";
        }
    }

    return 0;
}