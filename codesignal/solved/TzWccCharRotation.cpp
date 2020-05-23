/**
    Description (TzWccCharRotation)
    Given n Strings s1, s2, ..., sn each consisting of lowercase English letters.
    For this question, a single rotation of a String is defined as erasing the first character and appending it to the end of the String.
    For example:
    Given String = "ramanonaka", then one rotation of this string will return "amanonakar".
    Find the minimal number of rotations needed to perform in order to make all the n Strings equal.
    NOTE :
    If it is impossible to convert all the Strings into one desired String, then return -1.

    Input : n = 2 & arrayString = [ "jaojaoby" , "ojaobyja" ]
    Output : TzWccCharRotation(n,arrayString) = 2
    Explanation :
    Self Explanatory.
    Input : n = 3 & arrayString = [ "k" , "k" , "k" ]
    Output : TzWccCharRotation(n,arrayString) = 0
    Explanation :
    Self Explanatory.
    Input : n = 3 & arrayString = [ "aa" , "aa" , "ab" ]
    Output : TzWccCharRotation(n,arrayString) = -1
    Explanation :
    It is impossible to convert the third String into first two Strings by using above mentioned rotation technique.
    [execution time limit] 3 seconds (java)
    [input] integer n1 ≤ n < 10
    [input] array.string arrayStringToRotateLengths of each strings are equal.Lengths of each string is positive and does NOT exceed 50.
    [output] integerThe minimal number of rotations required in order to make all the strings equal.
**/

#include <bits/stdc++.h>

using namespace std;
int makeEqualByRotating(string a, string b) {
    int res = -1;
    if ( a.size() != b.size() ) return -1;
    if ( a.compare(b) == 0 ) return 0;
    int k = 1;
    while ( k < a.size() ) {
        string temp = "";
        for (int i = 0; i < a.size(); i++ ) {
            temp += a[ (i + k) % a.size() ];
        }
        if ( temp.compare(b) == 0) {
            return k;
        }
        k++;
    }
    return res;
}
int TzWccCharRotation(int n, std::vector<std::string> arrayStringToRotate) {
    int c = INT_MAX;
    std::vector<std::string> a = arrayStringToRotate;
    for (int i = 0; i < a.size(); i++) {
        int qt = 0;
        for (int j = 0; j < a.size(); j++) {
            int n_rot = makeEqualByRotating(a[j], a[i]);
            if ( n_rot != -1 ) {
                qt += n_rot;
                if ( qt > c ) {
                    continue;
                }
            } else {
                return -1;
            }
        }
        c = min(c, qt);
    }
    return c;
}
int main()
{
    int res = makeEqualByRotating("zwoxz", "zzwox");
    cout << res << endl;

    vector<std::string> arrayStringToRotate {
        "xzzwo"s,
        "zwoxz"s,
        "zzwox"s,
        "xzzwo"s
    };
    cout << "Value "
        << TzWccCharRotation(4, arrayStringToRotate)
        << endl;
    return 0;
}
