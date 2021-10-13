string funnyString(string a) {
    string res = "Funny";
    for (int i = 0, s = a.size(); i < s - 1; i++) {
        int t = s - 1;
        if (abs(a[i] - a[i + 1]) != abs(a[t - i - 1] - a[t - i]))
            return "Not " + res;
    }
    return res;
}
