#include <bits/stdc++.h>
using namespace std;
/*
Not yet fully solved... TLE (2sec)
*/
string solve (string &input) {
    stack<char> sofar;
    
    // pretty similar to the classical
    // match parenthesis problem
    // O(n)
    
    for (char c : input) {
        if (c == ' ') continue;
        if (!sofar.empty()) {
            if (c == sofar.top())
                sofar.pop();
            else
                sofar.push(c);
        } else {
            sofar.push(c);     
        }
    }
    
    if (sofar.empty())
        return "YES";
    return "NO";    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string t;
    getline(cin, t);
    
    int T = atoi(t.c_str());
    
    while (T--) {
        string str;
        getline(cin, str);
        cout << solve(str) << '\n';
    }
    return 0;
}
