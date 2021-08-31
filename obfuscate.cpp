#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string compile (string in) {
    assert (in.size() > 0);
    vector<pair<char, int>> ct;
    char curr = in [0]; int count = 1;
    for (int i = 1, s = (int) in.size(); i < (1 + s); i++) {
        if (i == s || in[i] != curr) {
            ct.push_back ({curr, count});
            count = 0;
        }
        curr = in[i];
        count++;
    }
    string res = "";
    for (auto &p : ct)
        res += p.first + to_string(p.second);
    return res;
}

vector<ll> crypt (string compiled) {
    vector<ll> list;
    return "";
}


int main() {
    string str = ":::::####:::###############:::###########::::::::::::::::::#.... ";
    cout << compile (str);
    return 0;
}
