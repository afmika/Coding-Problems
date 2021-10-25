#include <bits/stdc++.h>

using namespace std;
int main() {
    string input;
    std::getline(std::cin, input);
    int s = input.size();
    int i = 0;
    char pos = 'L';
    while (i < s) {
        char L = input[i++];
        char R = input[i++];
        string com = "";
        if ((pos == 'R' && R == '#') || (pos == 'L' && L == '#')) {
            if (pos == 'R') R = '-';
            if (pos == 'L') L = '-';
            com = "S";
        }
        if (R == '#' && pos != 'R') {
            pos = 'R';
            com += "RS";
        }
        if (L == '#' && pos != 'L') {
            pos = 'L';
            com += "LS";
        }
        if (com.compare("") == 0)
            com = "I";
            
        cout << com ;
        i++;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
