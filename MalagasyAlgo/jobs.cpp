#include <bits/stdc++.h>
using namespace std;

void showStateOf (map<string, pair<int, int>> jobs) {
    vector< pair<string, pair<int, int>> > temp (jobs.begin(), jobs.end());
    sort (temp.begin(), temp.end(), [&] (auto a, auto b) {
        pair<int, int> ca = a.second;
        pair<int, int> cb = b.second;
       if (ca.first == cb.first)
           return ca.second < cb.second;
        return ca.first < cb.first;
    });
    cout << "[";
    for (int i = 0; i < (int) temp.size(); i++) {
         cout << temp[i].first;
        if (i + 1 < (int) temp.size())
            cout << ", ";
    }
    cout << "]\n";
}

int main() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << "";
        return 0;
    }
    map<string, pair<int, int>> jobs;
    int date = 0;
    for (int i = 0; i < n; i++) {
        string cmd;
        string job;
        int count;
        cin >> cmd;
        if (cmd.compare("ADD") == 0) {
            cin >> job >> count;
            cerr << cmd  << " " << job << " " << count << " woo\n";
            if (jobs.find(job) == jobs.end()) {
                jobs[job] = make_pair(count, date++);               
            } else {
                jobs[job] = make_pair(count + jobs[job].first, date++);
            }
        } else if (cmd.compare("REMOVE") == 0) {
            cin >> job;
            jobs.erase(job);
        } else {
            // refresh
            showStateOf (jobs);
        }
    }
    return 0;
}
