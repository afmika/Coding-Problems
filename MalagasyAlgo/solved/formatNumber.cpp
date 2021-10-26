#include <bits/stdc++.h>

using namespace std;
/*

    Format 1: use <spaces> to separate thousands, and . (dots or period) to indicate the decimal place, e.g: 1 954.05
    Format 2: use , (comas) to separate thousands, and . (dots or period) to indicate the decimal place, e.g: 1,954.05
    Format 3: use <spaces> (comas) to separate thousands, and , (comas) to indicate the decimal place, e.g: 1 954,05
    Format 4: use . (dots or period) to separate thousands, and , (comas) to indicate the decimal place, e.g: 1.954,05

*/
unordered_map<int, pair<string, string>> fm {
    {1, {" ", "."}},  
    {2, {",", "."}},  
    {3, {" ", ","}},  
    {4, {".", ","}}  
};

string removeExcZero (string str) {
    if (str.compare("") == 0) return str;
    string res = "";
    bool ok = false;
    for (int i = str.size() - 1; i >= 0; i--) {
        if (str[i] != '0') ok = true;
        if (ok) {
            res = str[i] + res; 
        }
    }
    return res;
}

pair<string, string> splitDot (string number) {
    string n = "", d = "";
    bool gotDec = false;
    for (char q : number) {
        if (q == '.') {gotDec = true; continue; }
        if (gotDec) d += q;
        else n += q;
    }
    return make_pair (n, removeExcZero(d));
}

string formatIt (string number, string sep, string dec) {
    pair<string, string> sp = splitDot (number);
    string n = sp.first;
    string d = sp.second;
    int k = 0;
    string res = "";
    for(int i = n.size() - 1; i >= 0; i--) {
        res = n.substr(i, 1) + res;
        res = (k+1) % 3 == 0 && i != 0 ?  sep + res : ""+res;
        k++;
    }
    if (d.compare("") != 0) return res + dec + d;
    return res;
}

int main() {
    string n;
    int f;
    cin >> n >> f;
    
    string isNeg = "";
    if (fm.find(f) == fm.end()) {
        cout << "";
        return 0;
    }
    
    if (n[0] == '-') {
        isNeg = "-";
        n = n.substr(1);
        if (n.compare("0") == 0)
            n = "0";
    }
    if (n[0] == '.')
        n = "0" + n;
    
    string number = n;
    pair<string, string> curr = fm[f];
    string sep = curr.first;
    string dec = curr.second;
    
    cout << isNeg + formatIt (number, sep, dec);
    
    return 0;
}
