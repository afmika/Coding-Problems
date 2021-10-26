#include <bits/stdc++.h>
using namespace std;
string joinStr (set<string> frs) {
    string res = "";
    int i = 0;
    for (string fr : frs) {
        res += fr;
        if (i + 1 < (int) frs.size())
            res += ", ";
        i++;
    }
    return res;
}
int main() {
    int n;
    cin >> n;
    map<string, vector<string>> rel;
    map<string, bool> areFriend;
    for (int i = 0; i < n; i++) {
        string curr, with;
        cin >> curr >> with;
        if (rel.find(curr) == rel.end()) {
            rel[curr] = vector<string>{with};
        } else {
            rel[curr].push_back (with);        
        }
        if (rel.find(with) == rel.end()) {
            rel[with] = vector<string>{curr};
        } else {
            rel[with].push_back (curr);        
        }
        areFriend[curr + with] = true;
        areFriend[with + curr] = true;
    }
    
    map<string, set<string>> sug;
    for (auto pers : rel) {
        string name = pers.first;
        vector<string> friends = pers.second;
        for (string tomo : friends) {
            vector<string> fr = rel[tomo];
            for (string temp : fr) {
                if (temp.compare(name) != 0 )
                   sug[name].insert(temp);
            }
        }
    }
    for (auto p : sug) {
        cout << p.first << " [";
        cout << joinStr (p.second);
        cout << "]\n";
    }
    return 0;
}
