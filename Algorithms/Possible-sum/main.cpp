/**
 * @author afmika
 */
 
#include <bits/stdc++.h>
using namespace std;

map<double, bool> cloneMap(map<double, bool> m) {
    map<double, bool> r;
    for (auto c : m) r[c.first] = c.second;
    return r;
}
vector<double> cloneVec(vector<double> v) {
    vector<double> r;
    for (auto i : v) r.push_back(i);
    return r;
}

bool DFS (
          vector< vector<double> >& solutions,
          vector<double> current,
          double current_sum,
          double value,
          map<double, bool> coins
         )
{
    if ( current_sum == value ) {
        return true;
    }

    if ( current_sum > value) {
        return false;
    }

    for (auto coin : coins) {
        if ( coins[coin.first] == false ) {
            // updates
            map<double, bool> cur_coin_state = cloneMap( coins );
            cur_coin_state[coin.first] = true;

            vector< double > cur_sol = cloneVec( current );
            cur_sol.push_back(coin.first);

            double delta = value - (current_sum + coin.first);
            // we can do some optz here
            // we just need to store the minlength sol and
            // check if the current solution exceeds or not that minlength
            if ( DFS(solutions, cur_sol, current_sum + coin.first, value, cur_coin_state) ) {
                solutions.push_back( cur_sol );
            }
        }
    }
    return false;
}

vector<double> getMinimumCoins(vector<double> moneys, double value) {

    sort(moneys.begin(), moneys.end(), [&] (double a, double b) {
         return a > b;
    });


    map<double, bool> coins;
    for (auto coin : moneys) {
        if ( coin < value ) {
            coins[coin] = false;
        }
        if ( coin == value )
            return vector<double>{ value };
    }

    vector< vector<double> > solutions;
    vector<double> current;

    DFS( solutions, current, 0, value, coins);

    if ( solutions.size() == 0 ) {
        return vector<double>{-1};
    }

    // best == min size
    sort(solutions.begin(), solutions.end(), [&](auto a, auto b) {
        return a.size() < b.size();
    });

    for (auto sol : solutions) {
        double t = 0;
        for (double c : sol) {
            t += c;
            cout << c << " ";
        }
        cout << " = " << t;
        cout << endl;
    }

    return solutions[0];
}

int main() {
    vector<double> res = getMinimumCoins(
        {0.5, 0.1, 0.4, 4, 5, 3, 1},
        10
    );

    cout << "minimum" << endl;
    for (auto r : res) cout << r << " ";
    return 0;
}
