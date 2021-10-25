#include <bits/stdc++.h>
using namespace std;


int main() {
    string in;
    getline(cin, in);
    map<char, int> count;
    
    for (char &c : in)
        count[c]++;
    
    // helloword = 1h + 1e + 3l + 2o + 1w + 1r + 1d
    string charset = "helowrd";
    string occur   = "1132111";
    
    int ans = INT_MAX;
    for (int i = 0, s = charset.size(); i < s; i++) {
        char c  = charset[i];
        int occ = occur[i] - '0';
        ans = min (ans, count[c] / occ);
    }
    cout << ans;
    return 0;
}
