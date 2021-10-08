#include <bits/stdc++.h>

using namespace std;

int sumDivisors (int n) {
    int s = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) s += i;
    }
    return s;
}

unordered_set<int> allAbundant () {
    unordered_set<int> abt;
    for (int i = 12; i <= 28123; i++) {
        if (sumDivisors(i) > i) abt.insert(i);
    }
    return abt;
}

bool cannotBeWrittenAsSumAbt (unordered_set<int> &abt, int n) {
    if (n < 24) return true;
    for (int i = 12; i <= n; i++) {
        int L = n - i, R = i;
        // can be written as a sum of 2 abundants numbers
        if (abt.find(L) != abt.end() && abt.find(R) != abt.end())
            return false;
    }
    return true;
}

int solve (unordered_set<int> &abt) {
    int s = 0;
    for (int i = 1; i <= 28123; i++) {
        if (cannotBeWrittenAsSumAbt (abt, i)) s += i;
    }
    return s;
}

int main() {
    unordered_set<int> abt = allAbundant ();
    cout << solve(abt);
    return 0;
}