/*
Christy is interning at HackerRank. One day she has to distribute some chocolates to her colleagues. She is biased towards her friends and plans to give them more than the others. One of the program managers hears of this and tells her to make sure everyone gets the same number.

To make things difficult, she must equalize the number of chocolates in a series of operations. For each operation, she can give

chocolates to all but one colleague. Everyone who gets chocolate in a round receives the same number of pieces.

For example, assume the starting distribution is
. She can give bars to the first two and the distribution will be . On the next round, she gives the same two bars each, and everyone has the same number:

.

Given a starting distribution, calculate the minimum number of operations needed so that every colleague has the same number of chocolates.

Function Description

Complete the equal function in the editor below. It should return an integer that reperesents the minimum number of operations required.

equal has the following parameter(s):

    arr: an array of integers to equalize

Input Format

The first line contains an integer

, the number of test cases.

Each test case has
lines.
- The first line contains an integer , the number of colleagues.
- The second line contains

space-separated integers denoting the number of chocolates each colleague has.

Constraints



Number of initial chocolates each colleague has <

Output Format

Print the minimum number of operations needed for each test case, one to a line.

Sample Input

1
4
2 2 3 7

Sample Output

2

*/
#include <bits/stdc++.h>

using namespace std;

vector< int > allowed_dist = {1, 2, 5};

int countNbOperations(vector<int> distro ) {
    int count = 0;
    size_t size = distro.size();
    // int loop_count = 0;
    while ( true ) {
        int max_choco = -1;
        int iter = 1;
        bool all_equal = true;

        // On cherche le max pour reference, on check en meme temps
        // si la distribution est deja bonne
        for (size_t i = 0; i < size; i++) {
            max_choco = max(max_choco, distro[i]);
            if ( 1 + i < size)
            if ( distro[i] != distro[1 + i])
                all_equal = false;
        }

        // STOP si on est bon
        if ( all_equal ) {
            // cout << "-- N. loop " << loop_count << endl;
            return count;
        }

        vector<int> change_indicator;
        int max_diff = -1;
        for ( size_t i = 0; i < size; i++) {
            int diff = max_choco - distro[i];
            // 0 : aucun changement
            // -1 : devrait etre mise a jour
            change_indicator.push_back( diff != 0 );

            // on cherche parmis 1, 2, 5 le meilleur nombre qui
            // minimise la distance entre chaque distribution
            // de la courante iteration
            if ( diff > 5 ) {
                // on peut optimiser en cherchant
                // combien d'addition en 5 permettrait
                // de court-circuiter l'iteration
                iter = diff / 5;
                max_diff = max(diff, max_diff);
            } else if (iter == 1){
                for ( size_t i = 1; i < allowed_dist.size(); i++) {
                    int inf = allowed_dist[i-1],
                        sup = allowed_dist[i];
                    if ( inf <= diff && sup >= diff ) {
                        max_diff = max(max_diff, diff != sup ? inf : sup );
                        break;
                    }
                }
            }
        }
        // cout << " diff : "<< max_diff << " max choco " << max_choco << endl;
        for (size_t i = 0; i < size; i++) {
            if ( change_indicator[i] ) {
                if ( iter > 1 ) {
                    // combien de fois 5 pour raccourcir la distance ?
                    distro[i] += iter * 5;
                } else {
                    // ne se produit que quand max_diff <= 5
                    distro[i] += max_diff;
                }
            }
        }
        count += iter;
        // cout << "- iter " << count << endl;
        // for (auto c : distro) cout << " " << c ;
        // cout << endl;
        // loop_count++;
    }
    return count;
}

int main() {
    cout << countNbOperations( {1, 1, 5}) << endl; // 2
    cout << countNbOperations( {2, 2, 3, 7}) << endl; // 2
    cout << countNbOperations( {10, 7, 12}) << endl; // 3
    cout << countNbOperations( {1, 2, 3, 100000}) << endl; // 20002
	cout << countNbOperations( {3, 10001} ) << endl; // 2001
	cout << countNbOperations( {300, 350 } ) << endl; // 10
    cout << countNbOperations( {300, 301, 350, 1, 200, 50, 3, 841, 10000}) << endl; // 2405

    /*
    int n_test;
    cin >> n_test;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    vector< int > res;
    for (int i = 0; i < n_test; i++) {
        int n_colleagues;
        cin >> n_colleagues;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        vector<int> cur_distro;
        for (int i = 0; i < n_colleagues; i++) {
            int val;
            cin >> val;
            cur_distro.push_back( val );
        }
       res.push_back( countNbOperations( cur_distro ) );
    }
    for (int n : res) cout << n << endl;
    */
    return 0;
}
