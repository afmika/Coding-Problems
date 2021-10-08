#include <bits/stdc++.h>

using namespace std;


int main() {
    int target = 999999;
    string str = "0123456789";
    while (target-- && next_permutation (str.begin(), str.end()));
    cout << str;
    return 0;
}