/**
 * @author afmika
 * Problem : ex-aequo
 * AlgoMada Devfest Rookies Contest solution
 */

#include <bits/stdc++.h>
using namespace std;

struct Result {
    // R : rank, C : total number of people with the same rank, S : total score
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
    
    // sort by the total score in a descending order
    sort(results.begin(), results.end(), [&] (auto a, auto b) {
        return a.S > b.S;
    });
    
    int pos = 1; // rank
    for (auto res : results) {
        res.R = pos;
        res.show();
        // next rank := current rank + total number of persons sharing the same current rank
        pos = pos + res.C;
    }
}

int main() {
    // N : the number of participants, P : the number of problems
    int N, P;
    cin >> N >> P;
    vector<int> scores;
    
    while (N--) {
        // process the input
        // compute the total score of the current
        // participant at the same time
        int s = 0;
        for (int p = 0; p < P; p++) {
            int ds;
            cin >> ds;
            s += ds;
        }
        scores.push_back(s);
    }
    
    // for each score, we count the number of participants with the same total score value
    map<int, int> shares;
    for (int score : scores) {
        shares[score]++;
    }
    
    // this is more than enough to build the leaderboard
    // like an array, a map access takes O(1) in time
    // Compexity : O (P*N) in time / O(N) in space
    solveUsing (shares);
    return 0;
}
