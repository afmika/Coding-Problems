#include <iostream>
#include <vector>

using namespace std;
long long cp (long long a, long long b, bool sup) { return sup ? (a > b ? a : b) : (a < b ? a : b); }

// Complete the miniMaxSum function below.
void miniMaxSum(vector<int> arr) {
    long long mini = LONG_MAX, maxi = LONG_MIN;
    int s = arr.size();
    long long total = 0;
    for (long long a : arr) total += a;
    for (int hide = 0; hide < s; hide++) {
        mini = cp(mini, total - arr[hide], false);
        maxi = cp(maxi, total - arr[hide], true);        
    }
    cout << mini << " " << maxi;
}

int main () {
	miniMaxSum ({    769082435, 210437958, 673982045, 375809214, 380564127});
	return 0;
}