// https://www.hackerrank.com/challenges/crush/problem?isFullScreen=true

#include <bits/stdc++.h>

using namespace std;

typedef long int ll;
inline ll min(ll a, ll b) { return a < b ? a : b; }
inline ll max(ll a, ll b) { return a > b ? a : b; }

ll pick (long int n, long int b) {
    return min(max(n - b + 1, 0), 1);
}

int main() {
    ll n, q_count, nax = 0;
    cin >> n >> q_count;
    ll *height = new ll[n];
    while (q_count--) {
        // keep it simple and stupid
        ll a, b, k;
        cin >> a >> b >> k;
        height[a - 1] += k;
        height[b] -= k * pick(n, b);
    }
    
    ll cumul = 0;
    for (int i = 0; i < n; i++) {
        cumul += height[i];
        nax = max(nax, cumul);
    }
    cout << nax;
    return 0;
}
