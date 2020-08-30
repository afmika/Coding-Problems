#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

vi kMostFrequent(vi nums, int k) {
    map<int, int> m;
    for (int n : nums)
        m[n]++;
    vector<int> temp;
    for (auto pi : m) {
        temp.push_back(pi.first);
    }
    sort(temp.begin(), temp.end(), [&] (int a, int b) {
       return m[a] > m[b];
    });

    if ( k >= (int) temp.size()) {
        return temp;
    }

    vector<int> result;
    for (int i = 0; i < k; i++)
        result.push_back(temp[i]);
    return result;
}

int main() {
    vi res = kMostFrequent({3, 1,2, 2}, 2);
    cout << '\n';
    for (int n : res) {
        cout << n << ' ';
    }
    return 0;
}
