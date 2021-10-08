#include <bits/stdc++.h>

using namespace std;

string sum (string a, string b) {
    string c = "";
    int carry = 0;
    reverse (a.begin(), a.end());
    reverse (b.begin(), b.end());
    string up   = a.size() > b.size() ? a : b;
    string down = a.compare(up) == 0 ? b : a;
    
    int i = 0;
    while (i < (int) down.size()) {
        int l = up[i] - '0',
            r = down[i] - '0';
        int dsum = l + r;
        if (carry > 0) dsum += carry;
        carry = dsum >= 10 ? 1 : 0;
        c = to_string(dsum % 10) + c;   
        i++;
    }
    
    while (i < (int) up.size()) {
        int l = up[i] - '0';
        if (carry > 0) l += carry;
        carry = l >= 10 ? 1 : 0;
        c = to_string(l % 10) + c;
        i++;
    }
    
    return (carry == 0 ? "" : to_string(carry)) + c;
}

void runTests () {
    vector<pair<int, int>> tests {
        {17897, 457101},
        {20441,99971},
        {9009,4801},
        {9999, 1},
        {100999, 22}
    };
    
    for (auto test : tests) {
        string F = to_string(test.first), S = to_string(test.second);
        int res = test.first + test.second;
        string s_sum = sum(F, S);
        cout << F << " + " << S << " = " << res;
        if (to_string(res).compare(s_sum) == 0) {
            cout << " = " << s_sum << " Ok";
        } else {
            cout << " != " << s_sum << " Fail";
        }
        cout << "\n";
    }
}

string computeSum (vector<string> numbers) {
    string s = "0";
    for (string &n : numbers)
        s = sum(s, n);
    return s;
}

int main() {
    // runTests ();
    
    int n = 100;
    vector<string> numbers;
    
    while (n--) {
        string num;
        cin >> num;
        numbers.push_back(num);
    }
    
    string res = computeSum (numbers);
    cout << "10 first digits " << res.substr(0, 10);
    return 0;
}