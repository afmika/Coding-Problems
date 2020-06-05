/**
 * @author afmika
 */

#include <bits/stdc++.h>

using namespace std;

vector<char> cloneVec(vector<char> v) {
    vector<char> r;
    for (char c : v) r.push_back(c);
    return r;
}

bool DFS (
          vector< vector<char> >& solutions,
          vector<char> current,
          int pos,
          vector< vector<char> > letters_set
          )
{
    if ( current.size() == letters_set.size() ) {
        return true;
    }

    /**
     * Ex : letters_set = {{A,B}, {C,D,E}, {E,F,G}}
     * pos = [0] [1]    [2]
     *        A - C * -- E
     *        B   D   \  F
     *            E   \  G
     *
     **/

    if ( pos < letters_set.size() ) {
        for (char c : letters_set[pos] ) {
            vector<char> clone_cur = cloneVec( current );
            clone_cur.push_back( c );
            if ( DFS(solutions, clone_cur, pos + 1, letters_set) ) {
                solutions.push_back( clone_cur );
            }
        }
    }
    return false;
}
vector< vector<char> > getAllCombi(vector< vector<char> > letters_set) {
    vector< vector<char> > solutions;
    vector<char> current;
    DFS(solutions, current, 0, letters_set);
    return solutions;
}

int main() {
    vector< vector<char> > res = getAllCombi(
        {
            {'0', '1', '2'},
            {'A', 'B', 'C'},
            {'<', '>', '[', ']', '(', ')'}
        }
    );

    for (auto sol : res) {
        for (char c : sol) cout << c;
        cout << endl;
    }
    // Card S1 x Card S2 ... x Card SN = Total Size
    // in our case 3 x 3 x 6 = 54
    cout << "Total " << res.size() << " result(s)" << endl;

    return 0;
}
