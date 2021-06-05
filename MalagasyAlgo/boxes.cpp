#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void debugBox (vector<int> box) {
    printf ("w = %i, l = %i, h = %i\n", box[0], box[1], box[2]);
}

bool canFit (vector<int> ba, vector<int> bb) {
    if (ba[0] < bb[0]) return false;
    if (ba[1] < bb[1]) return false;
    if (ba[2] < bb[2]) return false;
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> boxes;
    for (int i = 0; i < n; i++) {
        int w, l, h;
        cin >> w >> l >> h;
        vector<int> box {w, l, h};
        boxes.push_back(box);
    }
    
    sort(boxes.begin(), boxes.end(), [&] (auto a, auto b) {
        for (int i = 0; i < 3; i++) {
            if (a[i] < b[i])
                return false;
            else if (a[i] > b[i])
                return true;
        }
        return false;
    });
    // for (auto b : boxes) {
    //     debugBox(b);
    // }  
    int c = 0;
    for (int i = 1; i < (int) boxes.size(); i++) {
        auto ba = boxes[i - 1], bb = boxes[i];
        if (canFit(ba, bb)) c++;
    }
    cout << (c > 0 ? c + 1 : c);

    return 0;
}
