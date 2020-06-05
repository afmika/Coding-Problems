/**
 * @author afmika
 * Simple DFSearch example
 */

#include <bits/stdc++.h>

using namespace std;

map<char, bool> cloneMap(map<char, bool> m) {
    map<char, bool> r;
    for (auto k : m) r[k.first] = k.second;
    return r;
}


bool DFS (vector<string>& solutions, string current, string initial_str, map<char, bool> m) {
    if ( current.size() == initial_str.size() ) {
        return true;
    }

    for (char c : initial_str) {
        if ( m[c] == false) {
            map<char, bool> clone_m = cloneMap( m );
            clone_m[c] = true;
            string temp = current + c;
            if ( DFS(solutions, temp, initial_str, clone_m) ) {
                solutions.push_back( temp );
            }
        }
    }

    return false;
}

vector<string> permut(string str) {
    map<char, bool> m;
    for (char c : str) m[c] = false;

    vector<string> solutions;
    string current;

    DFS (solutions, current, str, m);

    return solutions;
}

int main() {
    vector<string> res = permut("123456"s);
    for (string s : res ) cout << s << endl;
    cout << res.size() << " result(s)";
    return 0;
}
