#include <bits/stdc++.h>

using namespace std;

int getTotalX(vector<int> a, vector<int> b) {
    int count = 0;
    int min_b = *min_element(b.begin(), b.end());
    for (int q = 1; q <= min_b; q++) {
        int c = (int) a.size();
        for (int f : a)
            if (q % f == 0) --c;
        
        if (c == 0) {
			// asesy daholo ny b
			c = (int) b.size();
            for (int d : b)
                if (d % q == 0) --c;
            if (c == 0) count++;
        }
    }
    return count;
}

int main () {
	vector<int> a {1};
	vector<int> b {72, 48};
	cout << getTotalX (a, b);
	return 0;
}
