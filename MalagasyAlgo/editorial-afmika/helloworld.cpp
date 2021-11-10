/**
 * @author afmika
 * Problem : helloworld
 * AlgoMada Devfest Rookies Contest solution
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    string in;
    getline(cin, in);

    // count the redundancy of each character
    map<char, int> count;
    for (char &c : in)
        count[c]++;
    
    // we want to know how many 'helloworld' we can make using the input characters
    // a single 'helloword' contains 1 h + 1 e + 3 l + 2 o + 1 w + 1 r + 1 d
    string charset = "helowrd";
    string occur   = "1132111";
    
    int ans = INT_MAX;
    for (int i = 0, s = charset.size(); i < s; i++) {
        char c  = charset[i];     // the current character
        int occ = occur[i] - '0'; // total number of occurences of the current character in 'helloworld'
        // if        occ ---> 1 'helloworld'
        // then count[c] ---> ?
        // answer = count[c] * 1 / occ
        // /!\ the smallest redundant character has higher priority
        // hence the min function
        ans = min (ans, count[c] / occ);
    }
    cout << ans;
    return 0;
}
