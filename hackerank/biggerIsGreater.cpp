// https://www.hackerrank.com/challenges/bigger-is-greater/problem
string biggerIsGreater(string w) {
    string original = string(w.begin(), w.end());
    next_permutation(w.begin(), w.end());
    return w.compare(original) <= 0 ?
        "no answer" : w;
}