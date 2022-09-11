#include <bits/stdc++.h>

using namespace std;

#define M 1000000007

void display(pair<int, int> tree) {
	cout << tree.first << ", " << tree.second << "\n";
}

long naiveSolution (vector<pair<int, int>> &trees, vector<pair<int, int>> &wells) {
	long s = 0;
	for (auto &well : wells) {
		for (auto &tree : trees) {
			s += ((tree.first - well.first) * (tree.first - well.first) %  M
			+ (tree.second - well.second) * (tree.second - well.second) % M) % M;
		}
	}
	return s % M;
} 

long algebraTrick (vector<pair<int, int>> &trees, vector<pair<int, int>> &wells) {
	long s = 0;
	pair<int, int> gravity;
	long sx = 0, sy = 0, sqPxPy = 0;
	for (auto &tree : trees) {
		sx += (long) tree.first;
		sy += (long) tree.second;
		sqPxPy += tree.first * tree.first + tree.second * tree.second;
	}
	
	long N = (long) trees.size();
	
	for (auto &well : wells) {
		s +=  (N * (well.first * well.first + well.second * well.second)) % M
			+ sqPxPy % M
			- 2 * (well.first * sx + well.second * sy) % M;
	}
	
	return s % M;
}


int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	int c = 1;
	while (T--) {
		int N, Q;
		cin >> N;
		vector<pair<int, int>> wells, trees;
		while (N--) {
			int A, B;
			cin >> A >> B;
			trees.push_back({A, B});
		}
		cin >> Q;
		while (Q--) {
			int X, Y;
			cin >> X >> Y;
			wells.push_back({X, Y});
		}

		cout << "Case #" << c << ": " << algebraTrick(trees, wells) << "\n";
		c++;
	}
	return 0;
}
