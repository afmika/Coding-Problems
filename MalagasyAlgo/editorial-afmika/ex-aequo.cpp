/**
 * @author afmika
 * Problem : ex-aequo
 * AlgoMada Devfest Rookies Contest solution
 */

#include <bits/stdc++.h>
using namespace std;

struct Result {
    int R = 0, C = 0, S = 0;
    inline void show () {
        printf("%i %i %i\n", R, C, S);
    }
};

void solveUsing (map<int, int> scores) {
    vector<Result> results;
    for (auto score : scores) {
        Result res;
        res.S = score.first; // score value
        res.C = score.second; // share the same rank
        results.push_back(res);
    }
    
    sort(results.begin(), results.end(), [&] (auto a, auto b) {
        return a.S > b.S;
    });
    
    int pos = 1;
    for (auto res : results) {
        res.R = pos;
        res.show();
        pos = pos + res.C;
    }
}

int main() {
    int N, P, id = 0;
    cin >> N >> P;
    vector<int> scores;
    
    // total score
    while (N--) {
        int s = 0;
        for (int p = 0; p < P; p++) {
            int ds;
            cin >> ds;
            s += ds;
        }
        scores.push_back(s);
    }
    
    map<int, int> shares;
    for (int score : scores) {
        shares[score]++;
    }
    
    solveUsing (shares);
    return 0;
}
