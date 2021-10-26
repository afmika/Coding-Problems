/**
 * @author afmika
 * Problem : Balanced Sentence
 * AlgoMada Devfest Rookies Contest solution
 */

#include <bits/stdc++.h>
using namespace std;

// The keypoints in order to understand what the problem really want us to do are :
// - ignore the spaces
// - focus on the *even length* palindrome part

// An *even length* palindrome looks like this : hannah, 1221, goog, aa
// BUT here we are dealing with 'sentences' which may contain one or more palindromes
// with a brute force approach we have to generate all possible *even length* substrings
// we can do no better than O(n^2) in time complexity with this approach,
// that's way too much since 1 <= T[i].length <= 200000

// The trick is to use a stack then match every contiguous pair and remove it from our stack (pop it)
// this works everytime because an *even length* palindrome can be reduced into an empty string ''
// It runs O(n) in time / O(k) in space (k is the sum of the length of *non even length* palindromes, k <= n)
// for a single sentence of length n

// Let's take an example :
// input sentence = "hann ahi"
// stack <- empty, current_pos <- "[]hann ahi"
// step 1. stack <- "h"  , current_pos <- "[h]ann ahi"
// step 2. stack <- "ha" , current_pos <- "h[a]nn ahi"
// step 3. stack <- "han", current_pos <- "ha[n]n ahi"
// step 4. stack <- "ha" , current_pos <- "han[n] ahi", 'n' matches, remove the top
// step 5. stack <- "h"  , current_pos <- "hann [a]hi", 'a' matches, remove the top
// step 6. stack <- ""   , current_pos <- "hann a[h]i", 'h' matches, remove the top
// step 7. stack <- "i"  , current_pos <- "hann ah[i]"
// the stack is not empty therefore the input sentence is not balanced
// step 8. output "YES"

string solve (string &input) {
    stack<char> sofar;
    for (char c : input) {
        if (c == ' ') continue;
        if (!sofar.empty()) {
            if (c == sofar.top()) // yay it's a match !
                sofar.pop();
            else                 // no?
                sofar.push(c);
        } else {
            sofar.push(c);      // init
        }
    }
    return sofar.empty() ? "YES" : "NO";
}

int main() {
    // this part is not important
    string t;
    getline(cin, t);
    // we have T sentences to process in total
    int T = atoi(t.c_str());
    
    while (T--) {
        string str;
        getline(cin, str);
        cout << solve(str) << '\n';
    }
    return 0;
}
