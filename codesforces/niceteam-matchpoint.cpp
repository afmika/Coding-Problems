#include <bits/stdc++.h>
using namespace std;

int maxPairs(vector<int> &pos, int minDiff) {
    sort(pos.begin(), pos.end());
    int s = s = pos.size();
    int count = 0, i = 0, j = s / 2;
    while (i < s / 2) {
        while (j < s) {
            if (abs(pos[i] - pos[j]) >= minDiff) {
                count++;
                j++;
                break;
            }
            j++;
        }
        i++;
    }
    return count;
}

int main () {
    int n, dist;
    cin >> n >> dist;
    vector<int> input;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        input.push_back(v);
    }
    cout << maxPairs (input, dist);
}

