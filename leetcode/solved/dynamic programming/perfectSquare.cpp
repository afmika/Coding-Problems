#include <bits/stdc++.h>

using namespace std;

vector<int> squares;

void solve(int current_sq, int current_sum, int current_count, int& count, int input ) {
	if ( current_sum >= input ) {
		if ( current_sum == input ) {
			count = min(count, current_count);
			// printf(" = %d", input);
		}
		// printf("\n");
		return;
	}

	if ( current_count > count ) {
		return;
	}

	for (int sq : squares) {
		if ( current_sq > sq ) {
			int n = input / sq;
			for ( int t = n; t >= 1; t-- ) {
				// printf("%d*%d+", t, sq);
				solve(sq, current_sum + t * sq, current_count + t, count, input);
			}
		}
	}
}

int perfectSquare(int input) {
	for (int s = 1; s < input; s++ ) {
		int sq = s * s;
		if ( sq == input ) {
			return 1;
		}
		if ( sq > input ) break;
		else squares.push_back( sq );
	}
	
	sort(squares.rbegin(), squares.rend());

	int count = INT_MAX;
	
	solve(INT_MAX, 0, 0, count, input);
	
	return count == INT_MAX ? 1 : count;
}

int main(int argc, char* argv[]) {
	int input = stoi(argv[1]);
	cout << perfectSquare(input) << "\n";
	return 0;
}
