#include <bits/stdc++.h>

using namespace std;

void solve (vector<int> &in) {
    int count = 0, stairs_group = 0;
    string out = "";
    for (int i = 0, s = in.size(); i < s; i++) {
        count++;
        int curr = in[i], next = in[min(i + 1, s - 1)];
        if (curr >= next) {
            stairs_group++;
            out += to_string(count) + (curr + 1 == s ? "" : " ");
            count = 0;
        }
    }
    
    if (count > 0) out += to_string(count);
    cout << stairs_group << "\n" << out;
}

int main() {
	int n;
	cin >> n;
	vector<int> in;
	while (n--) {
		int a;
		cin >> a;
		in.push_back (a);
	}
	solve (in);
    return 0;
}