#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'maxPairs' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY skillLevel
 *  2. INTEGER minDiff
 */

int maxPairs(vector<int> skillLevel, int minDiff) {
    sort(skillLevel.begin(), skillLevel.end());
    int l = skillLevel.size();
    if ( l == 1 )
        return 0;
    if ( minDiff == 0 )
        return l / 2;
    int c = 0;
    int inf = 0, sup = l - 1;
	
	int delta = INT_MAX;
    while ( delta > 0 ) {
        int diff = skillLevel[sup--] - skillLevel[inf++];
        if ( diff >= minDiff ) {
			cout << skillLevel[inf - 1] << " + " << skillLevel[sup + 1] << "\n";
			cout << "--- " << (inf - 1) << " + " << (sup - 1) << "\n";
            c++;
        }		
        delta = sup - inf;
    }
    return c;
}


int main() {
	vector<int> couples = {1, 2, 3, 4, 5, 6};
	int minDiff = 4;
	cout << maxPairs(couples, minDiff);
	return 0;
}