int findDigits(int n) {
    string str = to_string(n);
    int c = 0;
    for (char &v : str) {
        if (v == '0' || n % (v - '0') != 0) continue;
        ++c;
    }
    return c;
}
